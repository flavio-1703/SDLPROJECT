#pragma once
#include <SDL.h>
#include <SDL_image.h>

class SDL_Setup
{
public:
	SDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight);
	~SDL_Setup();
	//getters
	SDL_Renderer* GetRenderer();
	SDL_Event* GetEvent();
	//functions
	void begin();
	void end();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainevent;
};

