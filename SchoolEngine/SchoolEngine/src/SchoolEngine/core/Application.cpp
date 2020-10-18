#include "Application.h"
#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include<iostream>

namespace SchoolEngine {
	Application::Application() {
		initialize();
	}

	Application::~Application() {
		SDL_Quit();
	}

	void Application::initialize() {
		if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
			std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

		if ((IMG_Init(IMG_INIT_PNG)) != 0)
			std::cout << "IMG_Init has failed. ERROR: " << SDL_GetError() << std::endl;

		if (() != 0) {
			std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;
		}
	}

	void Application::run() {

	}
}