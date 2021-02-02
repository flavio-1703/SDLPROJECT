#include "SDL_Setup.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


SDL_Setup::SDL_Setup(bool *quit, int ScreenWidth, int ScreenHeight)
{
	window = NULL;
	window = SDL_CreateWindow("Cancer", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "window couldn't be created" << std::endl;
		//return 0;
		*quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	mainevent = new SDL_Event();
}


SDL_Setup::~SDL_Setup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainevent;
}

SDL_Renderer* SDL_Setup::GetRenderer()
{
	return renderer;
}

SDL_Event* SDL_Setup::GetEvent()
{
	return mainevent;
}
//begin ending functions
void SDL_Setup::begin()
{
	SDL_PollEvent(mainevent);

	SDL_RenderClear(renderer); //clear screen
}

void SDL_Setup::end()
{
	SDL_RenderPresent(renderer);

}