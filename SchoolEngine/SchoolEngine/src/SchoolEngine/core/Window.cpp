#include "Window.h"
#include <stdio.h>
#include <iostream>

namespace SchoolEngine {
	Window::Window(const char* title, int w, int h) :_window(NULL), _renderer(NULL) {
		_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

		if (_window == NULL)
			std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

		_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	}

	SDL_Texture* Window::loadTexture(const char* filePath) {
		SDL_Texture* texture = NULL;
		texture = IMG_LoadTexture(_renderer, filePath);

		if (texture == NULL) {
			std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
		}

		return texture;
	}

	void Window::cleanUp() {
		SDL_DestroyWindow(_window);
	}
}