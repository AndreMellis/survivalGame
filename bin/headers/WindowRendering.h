#ifndef VAR_WINDOWRENEDERING
#define VAR_WINDOWRENEDERING

#define VAR_GAMENAME "survival"

#include  <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class WindowRendering {
private:
	static WindowRendering *pInstance;
	WindowRendering();
	~WindowRendering();
	SDL_Window *gWindow; //main game window
	SDL_Surface *gScreenSurface; //main game surface
	TTF_Font *gFont;
	void close(SDL_Surface *surface, SDL_Window *window);
public:
	static WindowRendering *getInstance();
};











#endif
