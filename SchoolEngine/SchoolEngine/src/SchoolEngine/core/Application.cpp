#include "Application.h"
#include "Window.h"
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
		if ((SDL_Init(SDL_INIT_VIDEO)) < 0)
			std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

		if ((IMG_Init(IMG_INIT_PNG)) < 0)
			std::cout << "IMG_Init has failed. ERROR: " << SDL_GetError() << std::endl;
	}

	void Application::run() {
		// Creates a window
		Window window("Test", 1280, 720);

		bool running = true;
		SDL_Event event;

		SDL_Texture* testTexture = window.loadTexture("Content/Textures/Sprites/TestSquareRed.png"); // TODO: REMOVE



		// Application Loop runs until event == SDL_QUIT
		while (running) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					running = false;
				}
			}

			window.clear();
			window.render(testTexture, 32, 32, 400, 400);
			window.display();
		}
		window.cleanUp();
	}
}