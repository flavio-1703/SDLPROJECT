#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

class CSprite
{
public:
	CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h);
	~CSprite();

	void draw();

	void SetX(float X);
	void SetY(float X);
	void SetPosition(float X, float Y);

	//get positions //getters
	float GetX();
	float GetY();
	//width and height
	void SetWidth(int W);
	void SetHeight(int H);
	
	int GetWidth();
	int GetHeight();
	//character origine
	void SetOrgin(float X, float Y);

	void pAnimation(int beginFrame, int endFrame, int Row, float Speed);
	void SetUpAnimation(int passedAmount_X, int passedAmount_y);

private:
	//postition
	float X_pos;
	float Y_pos;
	//float origins
	float orgin_x;
	float orgin_y;
	//
	SDL_Texture* image;
	SDL_Rect image_rect;

	SDL_Renderer* renderer;

	SDL_Rect crop;

	int img_width;
	int img_height;

	int CurrentFrame;
	int animationDelay;
	int AmountFrame_X;
	int AmountFrame_Y;


	
};

