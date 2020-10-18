#include "Window.h"
#include <stdio.h>
#include <iostream>

namespace SchoolEngine {
	Window::Window(const char* title, int w, int h) :_window(NULL), _renderer(NULL) {
		SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

		if (_window == NULL)
			std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}
}