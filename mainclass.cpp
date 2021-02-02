#include "mainclass.h"
#include <iostream>
#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>


mainclass::mainclass(int passed_ScreenWidth, int passed_ScreenHeight)
{
	quit = false;
	//screen resolution
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;

	sdl_setup = new SDL_Setup(&quit, ScreenWidth, ScreenHeight);
	//texture
	texture = new CSprite(sdl_setup->GetRenderer(),"texture.jpg", 0, 0, ScreenWidth, ScreenHeight);
	//charc
	charc = new CSprite(sdl_setup->GetRenderer(), "male.png", 100, 300, 80, 80);
	charc->SetUpAnimation(9, 4);
	//looks in no directions when it starts
	//charc origin
	charc->SetOrgin(charc->GetWidth()/2.0f, charc->GetHeight()/2.0f);


	//frame based ticks

	timecheck = SDL_GetTicks();

	//mause vars
	MauseX = 0;
	MauseY = 0;

	//bool
	follow = false;
	distance = 0;
	stopAnimation = false;

}


mainclass::~mainclass()
{
	delete sdl_setup;
	delete texture;
	delete charc;
}

double mainclass::GetDistance(int x1, int y1, int x2, int y2)
{
	double diffX = x1 -x2;
	double diffY = y1 - y2;
	double distance = sqrt((diffX * diffX) + (diffY * diffY));
	return distance;
}



void mainclass::GameLoop()
{
	while (!quit && sdl_setup->GetEvent()->type != SDL_QUIT)
	{
		//begin setup
		sdl_setup->begin();
		//mause state
		SDL_GetMouseState(&MauseX, &MauseY);

		//draw texture
		texture->draw();
		//draw character
		charc->draw();
		//switch statament

		float angle = atan2(follow_point_Y - charc->GetY(), follow_point_X - charc->GetX());
		angle = (angle * (180 / 3.14)) + 180;

		std::cout << angle << std::endl;
		

	
		if (!stopAnimation)
		{
			if (angle > 45 && angle <= 135)
			{
				//up
				if (distance > 15)
					charc->pAnimation(0, 2, 0, 150);
				else
					charc->pAnimation(0, 0, 0, 150);
			}
			else if (angle > 135 && angle <= 225)
			{
				//right
				if (distance > 15)
					charc->pAnimation(0, 2, 3, 150);
				else
					charc->pAnimation(0, 0, 3, 150);

			}
			else if (angle > 225 && angle <= 315)
			{
				//down
				if (distance > 15)
					charc->pAnimation(0, 2, 2, 150);
				else
					charc->pAnimation(0, 0, 2, 150);
			}
			else if ((angle <= 360 && angle > 315) || (angle >= 0 && angle <= 45))
			{
				//left
				if (distance > 15)
					charc->pAnimation(0, 2, 1, 150);
				else
					charc->pAnimation(0, 0, 1, 150);
			}


		}

		if (sdl_setup->GetEvent()->type == SDL_MOUSEBUTTONDOWN || sdl_setup->GetEvent()->type == SDL_MOUSEMOTION)
		{
			if (sdl_setup->GetEvent()->button.button == SDL_BUTTON_LEFT)
			{
				follow_point_X = MauseX;
				follow_point_Y = MauseY;
				follow = true;
			}
		}
		

		if (timecheck+5 < SDL_GetTicks() && follow)
		{

			distance = GetDistance(charc->GetX(), charc->GetY(), follow_point_X, follow_point_Y);
			if (distance == 0)
			{
				stopAnimation = true;
			}
			else
			{
				stopAnimation = false;
			}

			if (distance > 15)
			{

				if (charc->GetX() != follow_point_X)
				{
					charc->SetX(charc->GetX() - ((charc->GetX() - follow_point_X) / distance) *1.5f);
				}
	

				if (charc->GetY() != follow_point_Y)
				{
					charc->SetY(charc->GetY() - ((charc->GetY() - follow_point_Y) / distance) *1.5f);
				}

				else
				{
					follow = false;
				}

			}
			timecheck = SDL_GetTicks();

		}
			//end setup
			sdl_setup->end();

		}

	}
