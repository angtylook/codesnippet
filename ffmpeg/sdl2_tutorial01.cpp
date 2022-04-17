#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_timer.h"

#include <Windows.h>

#if 0
int main(int argc, char** argv) {
#endif
int WinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR lpCmdLine,
                      int nShowCmd) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return 0;
  }
  SDL_Window* win =
      SDL_CreateWindow("Win", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       640, 320, SDL_WINDOW_SHOWN);
  Uint32 render_flag = SDL_RENDERER_ACCELERATED;
  SDL_Renderer* render = SDL_CreateRenderer(win, -1, render_flag);
  SDL_Surface* surface = IMG_Load("002.png");
  SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
  SDL_FreeSurface(surface);
  SDL_Rect dest;
  SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
  dest.w /= 3;
  dest.h /= 3;
  dest.x = (640 - dest.w) / 2;
  dest.y = (320 - dest.h) / 2;
  bool close = false;
  int speed = 100;
  while (!close) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          close = true;
          break;
        case SDL_KEYDOWN:
          // keyboard API for key pressed
          switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
              dest.y -= speed / 10;
              break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
              dest.x -= speed / 10;
              break;
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
              dest.y += speed / 10;
              break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
              dest.x += speed / 10;
              break;
          }
        default:
          break;
      }
    }
    // right boundary
    if (dest.x + dest.w > 640)
      dest.x = 640 - dest.w;

    // left boundary
    if (dest.x < 0)
      dest.x = 0;

    // bottom boundary
    if (dest.y + dest.h > 320)
      dest.y = 320 - dest.h;

    // upper boundary
    if (dest.y < 0)
      dest.y = 0;

    // clears the screen
    SDL_RenderClear(render);
    SDL_RenderCopy(render, texture, NULL, &dest);

    // triggers the double buffers
    // for multiple rendering
    SDL_RenderPresent(render);

    // calculates to 60 fps
    SDL_Delay(1000 / 60);
  }
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  return 0;
}