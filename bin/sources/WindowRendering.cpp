#include "WindowRendering.h"
#include  <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdexcept>

WindowRendering *WindowRendering::pInstance = nullptr;

WindowRendering::WindowRendering()
{ // let's init everything here
	gWindow = nullptr;
	gRenderer = nullptr;
	gTextureBuffer = nullptr;

	if (SDL_Init (SDL_INIT_VIDEO) < 0)
	{ // failed to initialize video
		std::cerr << "failed to initialize SDL Video! SDL_Error:" << SDL_GetError() << "\n";
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
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED ); //create the renderer
			if ( !gRenderer)
			{
				std::cerr << "failed to create Renderer! SDL_Error:" << SDL_GetError() << "\n";
				exit(1); //fail out the program
			} else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //draw in white

				//initialize png loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ) //load png and make sure it actuall was png
				{ 
					std::cerr << "SDL_Image failed to initialize! IMG_Error:" << IMG_GetError() << "\n";
					exit(1); //fail out the program
				} else
				{
					windowHeight = SDL_GetWindowSurface(gWindow)->h;
					windowWidth = SDL_GetWindowSurface(gWindow)->w;
	
					printf("screen is of size  X: %d Y: %d\n", windowWidth, windowHeight);
				}

			}

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

void WindowRendering::close()
{
	SDL_DestroyTexture (gTextureBuffer);
	gTextureBuffer = nullptr;

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}

SDL_Texture *WindowRendering::loadTexture(std::string pngPath)
{ //loads a texture from an image and returns texture
	SDL_Texture *newTexture = nullptr; //a temp pointer to the texture that will eventually live in the heap

	SDL_Surface *loadedSurface = IMG_Load( pngPath.c_str() );
	if( !loadedSurface )
	{
		printf("Failed to load image %s! SDL_Image error: %s\n", pngPath.c_str(), IMG_GetError());
	} else
	{
		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( !newTexture )
		{
			printf ("Unable to create texture from %s! SDL Error: %s\n", pngPath.c_str(), SDL_GetError());
		}

		SDL_FreeSurface( loadedSurface ); //delete loadedSurface from heap
	}

	return newTexture;
}

bool WindowRendering::loadMedia(std::string pngPath)
{
	gTextureBuffer = nullptr; //null out gTextureBuffer incase this isn't first time using
	gTextureBuffer = loadTexture(pngPath); //private function, not SDL

	return (gTextureBuffer != nullptr); //returns true 
}

void WindowRendering::renderToBuffer(std::string pngPath, SDL_Rect *rectToFill)
{//takes in a png path and renders it to the given rect
	if( loadMedia(pngPath) )
	{ //media was loaded
		SDL_RenderCopy( gRenderer, gTextureBuffer, NULL, rectToFill);		
	} else
	{
		printf("failed to load %s\n", pngPath.c_str());
	}
}

void WindowRendering::clearBuffer( std::string pngBackground )
{
	SDL_RenderClear( gRenderer );

	SDL_Rect wholeScreen;
	wholeScreen.x = 0;
	wholeScreen.y = 0;
	wholeScreen.w = windowWidth;
	wholeScreen.h = windowHeight;

	if( loadMedia(pngBackground) )
	{ //media was loaded
		SDL_RenderCopy( gRenderer, gTextureBuffer, NULL, &wholeScreen);		
	} else
	{
		printf("failed to load %s\n", pngBackground.c_str());
	}
}
