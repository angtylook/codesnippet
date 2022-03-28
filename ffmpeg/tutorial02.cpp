#include <Windows.h>

// #define SDL_MAIN_NEEDED
// #define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_timer.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>
}

int main(int argc, char* argv[]) {
  AVFormatContext* pFormatCtx = NULL;
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return 0;
  }

  // Open video file
  if (avformat_open_input(&pFormatCtx, argv[1], NULL, NULL) != 0) {
    return -1;
  }
  if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
    return -1;
  }
  av_dump_format(pFormatCtx, 0, argv[1], 0);

  int videoStream = -1;
  int i;
  for (i = 0; i < pFormatCtx->nb_streams; i++) {
    if (pFormatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
      videoStream = i;
      break;
    }
  }
  if (videoStream == -1) {
    return -1;
  }

  AVCodec* pCodec = NULL;
  pCodec = avcodec_find_decoder(
      pFormatCtx->streams[videoStream]->codecpar->codec_id);
  if (pCodec == NULL) {
    fprintf(stderr, "Unsupported codec!\n");
    return -1;
  }

  AVCodecContext* pCodecCtx = NULL;
  pCodecCtx = avcodec_alloc_context3(pCodec);
  if (avcodec_parameters_to_context(
          pCodecCtx, pFormatCtx->streams[videoStream]->codecpar) < 0) {
    fprintf(stderr, "Couldn't copy codec param context");
    return -1;
  }

  if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
    return -1;
  }

  AVFrame* pFrameRGB = av_frame_alloc();
  if (pFrameRGB == NULL) {
    return -1;
  }

  // init sdl2
  SDL_Window* win =
      SDL_CreateWindow("Win", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       pCodecCtx->width, pCodecCtx->height, SDL_WINDOW_SHOWN);
  Uint32 render_flag = SDL_RENDERER_ACCELERATED;
  SDL_Renderer* render = SDL_CreateRenderer(win, -1, render_flag);
  SDL_Texture* texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGB24,
                                           SDL_TEXTUREACCESS_STREAMING,
                                           pCodecCtx->width, pCodecCtx->height);
  SDL_Rect rect{0, 0, pCodecCtx->width, pCodecCtx->height};
  uint8_t* buffer = NULL;
  int numBytes;
  numBytes = av_image_get_buffer_size(AV_PIX_FMT_BGR24, pCodecCtx->width,
                                      pCodecCtx->height, 1);
  buffer = (uint8_t*)av_malloc(numBytes * sizeof(uint8_t));
  av_image_fill_arrays(pFrameRGB->data, pFrameRGB->linesize, buffer,
                       AV_PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height,
                       1);

  AVFrame* pFrame = NULL;
  pFrame = av_frame_alloc();
  struct SwsContext* sws_ctx = NULL;
  sws_ctx = sws_getContext(
      pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt, pCodecCtx->width,
      pCodecCtx->height, AV_PIX_FMT_RGB24, SWS_BILINEAR, NULL, NULL, NULL);

  AVPacket packet;
  i = 0;
  int reponse = 0;
  bool close = false;
  while (av_read_frame(pFormatCtx, &packet) >= 0 && !close) {
    if (packet.stream_index == videoStream) {
      int response = avcodec_send_packet(pCodecCtx, &packet);
      if (response < 0) {
        av_packet_unref(&packet);
        break;
      }
      reponse = avcodec_receive_frame(pCodecCtx, pFrame);
      if (response == AVERROR(EAGAIN) || reponse == AVERROR_EOF) {
        av_packet_unref(&packet);
        continue;
      }
      sws_scale(sws_ctx, (const uint8_t* const*)pFrame->data, pFrame->linesize,
                0, pCodecCtx->height, pFrameRGB->data, pFrameRGB->linesize);
      // if (++i <= 5) {
      //   SaveFrame(pFrameRGB, pCodecCtx->width, pCodecCtx->height, i);
      // }
      SDL_UpdateTexture(texture, &rect, pFrameRGB->data[0],
                        pFrameRGB->linesize[0]);
      // clears the screen
      SDL_RenderClear(render);
      SDL_RenderCopy(render, texture, NULL, NULL);

      // triggers the double buffers
      // for multiple rendering
      SDL_RenderPresent(render);
      SDL_Event event;
      while (SDL_PollEvent(&event) > 0) {
        switch (event.type) {
          case SDL_QUIT:
            close = true;
            break;
        }
      }
      SDL_Delay(33);
    }
    av_packet_unref(&packet);
  }
  av_free(buffer);
  av_free(pFrameRGB);
  av_free(pFrame);
  avcodec_close(pCodecCtx);
  avformat_close_input(&pFormatCtx);
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  return 0;
}
