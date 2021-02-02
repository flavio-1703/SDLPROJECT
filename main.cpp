#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "mainclass.h"
using namespace std;


int main(int argc, char* args[])
{
	mainclass* main = new mainclass(1080, 720);
	main->GameLoop();

	delete main;

	return 0;
}