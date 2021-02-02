#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Setup.h"
#include "Sprite.h"
#include <math.h>

class mainclass
{
public:
	mainclass(int passed_ScreenWidth, int passed_ScreenHeight);
	~mainclass();

	void GameLoop();

	//get distance getter
	double GetDistance(int x1, int y1, int x2, int y2);


private:
	bool quit;
	//screen resolution
	int ScreenWidth;
	int ScreenHeight;
	//texture
	CSprite* texture;
	//character
	CSprite* charc;

	SDL_Setup* sdl_setup;

	//position boolean keyboard

	//frame based vars
	int timecheck;
	//mause position

	int MauseX;
	int MauseY;

	//some booleans

	bool follow;

	//character follow 

	int follow_point_X;
	int follow_point_Y;

	float distance;

	bool stopAnimation;


};

