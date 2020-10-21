#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "../util/Point.h"

namespace SchoolEngine {
	class Window {

	public:
		// Creates a window with specified title and size
		Window(const char* title, int w, int h);
		// Loads a texture based on filePath
		SDL_Texture* loadTexture(const char* filePath);
		// Run before closing the window (when the application is exited)
		void cleanUp();
		void clear();
		void render(SDL_Texture* tex, float sizeX, float sizeY, unsigned short  int posX, unsigned short  int posY, float angle, SDL_Point center, SDL_RendererFlip flip);
		void display();
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
	};
}