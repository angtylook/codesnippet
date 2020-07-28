#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

void SaveFrame(AVFrame *pFrame, int width, int height, int iFrame)
{
	FILE *pFile;
	char szFilename[32];
	int y;

	// Open file
	sprintf(szFilename, "frame%d.ppm", iFrame);
	pFile = fopen(szFilename, "wb");
	if (pFile == NULL)
		return;

	// Write header
	fprintf(pFile, "P6\n%d %d\n255\n", width, height);

	// Write pixel data
	for (y = 0; y < height; y++)
		fwrite(pFrame->data[0] + y * pFrame->linesize[0], 1, width * 3, pFile);

	// Close file
	fclose(pFile);
}

int main(int argc, char **argv)
{
	av_register_all();
	AVFormatContext *pFormatCtx = NULL;
	// Open video file
	if (avformat_open_input(&pFormatCtx, argv[1], NULL, NULL) != 0)
	{
		return -1;
	}
	if (avformat_find_stream_info(pFormatCtx, NULL) < 0)
	{
		return -1;
	}
	av_dump_format(pFormatCtx, 0, argv[1], 0);

	AVCodecContext *pCodecCtxOrig = NULL;
	AVCodecContext *pCodecCtx = NULL;

	int videoStream = -1;
	int i;
	for (i = 0; i < pFormatCtx->nb_streams; i++)
	{
		if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
		{
			videoStream = i;
			break;
		}
	}
	if (videoStream == -1)
	{
		return -1;
	}
	pCodecCtxOrig = pFormatCtx->streams[videoStream]->codec;
	AVCodec *pCodec = NULL;
	pCodec = avcodec_find_decoder(pCodecCtxOrig->codec_id);
	if (pCodec == NULL)
	{
		fprintf(stderr, "Unsupported codec!\n");
		return -1;
	}

	pCodecCtx = avcodec_alloc_context3(pCodec);
	if (avcodec_copy_context(pCodecCtx, pCodecCtxOrig) != 0)
	{
		fprintf(stderr, "Couldn't copy codec context");
		return -1;
	}

	if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0)
	{
		return -1;
	}

	AVFrame *pFrameRGB = av_frame_alloc();
	if (pFrameRGB == NULL)
	{
		return -1;
	}

	uint8_t *buffer = NULL;
	int numBytes;
	numBytes = avpicture_get_size(AV_PIX_FMT_BGR24, pCodecCtx->width, pCodecCtx->height);
	buffer = (uint8_t *)av_malloc(numBytes * sizeof(uint8_t));
	avpicture_fill((AVPicture *)pFrameRGB, buffer, AV_PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height);

	AVFrame *pFrame = NULL;
	pFrame = av_frame_alloc();
	struct SwsContext *sws_ctx = NULL;
	sws_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,
							 pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGB24,
							 SWS_BILINEAR, NULL, NULL, NULL);

	int frameFinished;
	AVPacket packet;
	i = 0;
	while (av_read_frame(pFormatCtx, &packet) >= 0)
	{
		if (packet.stream_index == videoStream)
		{
			avcodec_decode_video2(pCodecCtx, pFrame, &frameFinished, &packet);
			// did we get a video frame ?
			if (frameFinished)
			{
				sws_scale(sws_ctx, (uint8_t const *)pFrame->data, pFrame->linesize, 0, pCodecCtx->height,
						  pFrameRGB->data, pFrameRGB->linesize);
				if (++i <= 5)
				{
					SaveFrame(pFrameRGB, pCodecCtx->width, pCodecCtx->height, i);
				}
			}
		}
		av_free_packet(&packet);
	}
	av_free(buffer);
	av_free(pFrameRGB);
	av_free(pFrame);
	avcodec_close(pCodecCtx);
	avcodec_close(pCodecCtxOrig);
	avformat_close_input(&pFormatCtx);
	return 0;
}
