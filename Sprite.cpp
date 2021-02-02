#include "Sprite.h"
//basic includes
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>


CSprite::CSprite(SDL_Renderer* passed_renderer,std::string FilePath, int x, int y, int w, int h)
{
	renderer = passed_renderer;

	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());
	if (image == NULL)
	{
		std::cout << "image couldnt load" << FilePath.c_str() << std::endl;
	}

	image_rect.x = x;
	image_rect.y = y;
	image_rect.w = w;
	image_rect.h = h;

	X_pos = x;
	Y_pos = y;
	// character origin
	orgin_x = 0;
	orgin_y = 0;

	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);

	crop.x = 0;
	crop.y = 0;
	crop.w = img_width;
	crop.h = img_height;

	CurrentFrame = 0;
	AmountFrame_X = 0;
	AmountFrame_Y = 0;

}


void CSprite::pAnimation(int beginFrame, int endFrame, int Row, float Speed)
{
	if (animationDelay + Speed < SDL_GetTicks())
	{
		if (endFrame <= CurrentFrame)
		{
			CurrentFrame = beginFrame;
		}
		else
			CurrentFrame++;


		crop.x = CurrentFrame * (img_width / AmountFrame_X);
		crop.y = Row * (img_height / AmountFrame_Y);
		crop.w = img_width / AmountFrame_X;
		crop.h = img_height / AmountFrame_Y;

		animationDelay = SDL_GetTicks();
	}

}


void CSprite::SetUpAnimation(int passedAmount_X, int passedAmount_Y) 
{
	AmountFrame_X = passedAmount_X;
	AmountFrame_Y = passedAmount_Y;

}



CSprite::~CSprite()
{
	SDL_DestroyTexture(image);
}

//draw

void CSprite::draw()
{
	SDL_RenderCopy(renderer, image, &crop, &image_rect);
}

//character postition

void CSprite::SetX(float X)
{
	X_pos = X;

	image_rect.x = int(X_pos - orgin_x);

}

void CSprite::SetY(float Y)
{
	Y_pos = Y;

	image_rect.y = int(Y_pos - orgin_y);
}

void CSprite::SetPosition(float X, float Y)
{
	X_pos = X;
	Y_pos = Y;
	image_rect.x = int(X_pos - orgin_x);
	image_rect.y = int(Y_pos - orgin_y);

}

//get the position of the character


float CSprite::GetX()
{
	return X_pos;
}

float CSprite::GetY()
{
	return Y_pos;
}


void CSprite::SetOrgin(float X, float Y)
{
	orgin_y = Y;
	orgin_x = X;

	SetPosition(GetX(), GetY());
}
//setters
void CSprite::SetWidth(int W)
{
	image_rect.w = W;
}

void CSprite::SetHeight(int H)
{
	image_rect.h = H;
}

//getters
int CSprite::GetWidth()
{
	return image_rect.w;
}

int CSprite::GetHeight()
{
	return image_rect.h;
}





