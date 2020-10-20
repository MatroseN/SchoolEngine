#include "Window.h"
#include <stdio.h>
#include <iostream>

namespace SchoolEngine {
	Window::Window(const char* title, int w, int h) :_window(NULL), _renderer(NULL) {
		_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

		if (_window == NULL) {
			std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
		}
		else {
			std::cout << "Window created!" << std::endl;
		}
<<<<<<< HEAD
			
=======

>>>>>>> main

		_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

		if (_renderer == NULL) {
<<<<<<< HEAD
			std::cout << "´Renderer failed to init. Error: " << SDL_GetError() << std::endl;
=======
			std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
>>>>>>> main
		}
		else {
			std::cout << "Renderer created!" << std::endl;
		}
	}

	SDL_Texture* Window::loadTexture(const char* filePath) {
		SDL_Texture* texture = NULL;
		texture = IMG_LoadTexture(_renderer, filePath);

		if (texture == NULL) {
			std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
		}

		return texture;
	}

<<<<<<< HEAD
=======
	void Window::render(SDL_Texture* tex, unsigned short  int sizeX, unsigned short  int sizeY, unsigned short  int posX, unsigned short  int posY) {
		SDL_Rect src;
		src.x = 0;
		src.y = 0;
		src.w = sizeX;
		src.h = sizeY;

		SDL_Rect dst;
		dst.x = posX;
		dst.y = posY;
		dst.w = src.w;
		dst.h = src.h;

		SDL_RenderCopy(_renderer, tex, &src, &dst);
	}

	void Window::display() {
		SDL_RenderPresent(_renderer);
	}

	void Window::clear() {
		SDL_RenderClear(_renderer);
	}

>>>>>>> main
	void Window::cleanUp() {
		SDL_DestroyWindow(_window);
		std::cout << "Window destroyed!" << std::endl;
	}
}