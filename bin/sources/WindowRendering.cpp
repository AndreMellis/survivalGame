#include "WindowRendering.h"
#include  <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <stdexcept>

WindowRendering *WindowRendering::pInstance = nullptr;

WindowRendering::WindowRendering()
{ // let's init everything here
	gWindow = nullptr;
	gScreenSurface = nullptr;
	gFont = nullptr;

	if (SDL_Init (SDL_INIT_VIDEO) < 0)
	{ // failed to initialize video
		std::cerr << "failed to initialize SDL Video! SDL_Error:" << SDL_GetError() << "\n";
		exit(1); //fail out the program
	} else
		if (TTF_Init() == -1)
		{
			std::cerr << "failed to initialize SDL TTF! TTF_Erro:" << TTF_GetError() << "\n";
			exit(1); //fail out the program
		} else
		{
			gWindow = SDL_CreateWindow(VAR_GAMENAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP); //create fullscreen window

			if (!gWindow)
			{ //failed to create Window
				std::cerr << "failed to create Window! SDL_Error:" << SDL_GetError() << "\n";
				exit(1); //fail out the program
			} else
			{
				gScreenSurface = SDL_GetWindowSurface(gWindow); 
			}
		}
}

WindowRendering *WindowRendering::getInstance()
{
	if ( !pInstance)
	{ // no instance created yet
		pInstance = new WindowRendering(); //create new instance in the heap
	}
	return pInstance;
}

void close(SDL_Surface *surface, SDL_Window *window)
{
	SDL_FreeSurface(surface);
	surface = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}
