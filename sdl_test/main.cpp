#include <iostream>
#include <SDL2/SDL.h>

/*
 * Lesson 0: Test to make sure SDL is setup properly
 */
int main(int, char**){
  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }
  std::cout << "Plaform: " << SDL_GetPlatform() << std::endl;
  SDL_Quit();
  return 0;
}
