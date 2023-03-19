#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <SDL2/SDL.h>

const char *WINDOW_TITLE = "CHIP8_FLOAT";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const uint8_t DISPLAY_WIDTH = 64;
const uint8_t DISPLAY_HEIGHT = 32;
uint8_t *buffer = NULL;

int main(int argc,char *argv[]) {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Failed to initialize SDL2: %s\n", SDL_GetError());
    exit(-1);
  }

  SDL_Window *window = SDL_CreateWindow(
    WINDOW_TITLE,
    SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH,WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN
  );

  if(!window) {
    printf("Failed to create SDL2 Window: %s\n", SDL_GetError());
    SDL_Quit();
    exit(-1);
  }

  int running = 1;
  SDL_Event evnt;
  while(running) {
    while(SDL_PollEvent(&evnt)) {
      switch(evnt.type) {
        case SDL_QUIT: running = 0; break;
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
