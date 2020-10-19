#pragma once
#include <SDL.h>
#include <SDL_image.h>

namespace SchoolEngine {
	class Window {

	public:
		// Creates a window with specified title and size
		Window(const char* title, int w, int h);
		// Loads a texture based on filePath
		SDL_Texture* loadTexture(const char* filePath);
		// Run before closing the window (when the application is exited)
		void cleanUp();
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
	};
}