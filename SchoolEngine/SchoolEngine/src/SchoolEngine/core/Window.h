#pragma once
#include <SDL.h>
#include <SDL_image.h>

namespace SchoolEngine {
	class Window {

	public:
		Window(const char* title, int w, int h);
		~Window();
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
	};
}