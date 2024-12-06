#ifndef VAR_WINDOWRENEDERING
#define VAR_WINDOWRENEDERING

#define VAR_GAMENAME "survival"

#include  <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class WindowRendering {
private:
	static WindowRendering *pInstance;
	WindowRendering();
	~WindowRendering();
	SDL_Window *gWindow; //main game window
	SDL_Renderer *gRenderer; //main renderer of the game
	SDL_Texture *gTextureBuffer; //as we start loading different textures, it will be stored here

	int windowHeight;
	int windowWidth;
	SDL_Texture *loadTexture(std::string pngPath); //loads a texture from an image and returns texture
	bool loadMedia(std::string pngPath); //buffers png to the rectangle provided 
public:
	void close();
	static WindowRendering *getInstance();
	void clearBuffer() { SDL_RenderClear( gRenderer );} //must call before below
	void renderToBuffer(std::string pngPath, SDL_Rect *rectToFill); //takes in a png path and renders it to the given rect
	void renderPresent() { SDL_RenderPresent( gRenderer ); } //writes buffer to screen
	int getWindowW() { return windowWidth; }
	int getWindowH() { return windowHeight; }
};











#endif
