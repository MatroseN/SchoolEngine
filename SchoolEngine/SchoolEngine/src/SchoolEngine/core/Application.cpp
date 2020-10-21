#include "Application.h"
#include "Window.h"
#include "../util/Factory.h"
#include "../util/Point.h"
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
		Window window("Test", 1366, 720);

		bool running = true;
		SDL_Event event;

		SDL_Texture* testTexture = window.loadTexture("Content/Textures/Sprites/TestSquareRed.png"); // TODO: REMOVE

		for (int i = 0; i < 20; i++) {
			entt::entity e = makeSquare(reg);
		}

		auto view = reg.view<Point>();

		int x = 50;
		int y = 300;
		float sizeX = 32.0f;
		float sizeY = 32.0f;
		float angle = 0;
		SDL_Point center = { sizeX / 2, sizeY / 2 };
		SDL_RendererFlip flip = SDL_FLIP_NONE;

		const int adder = 64;

		for (const entt::entity entity : view) {
			Point& pos = view.get<Point>(entity);
			pos.X = x;
			pos.Y = y;

			x += adder;
		}


		float currentTime = SDL_GetTicks();
		float lastTime = currentTime;
		float deltaTime = (currentTime - lastTime) / 1000.0f;

		// Application Loop runs until event == SDL_QUIT
		while (running) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					running = false;
				}
			}

			currentTime = SDL_GetTicks();
			deltaTime = (currentTime - lastTime) / 1000.0f;

			auto view = reg.view<Point>();

			window.clear();
			for (const entt::entity entity : view) {
				Point& pos = view.get<Point>(entity);
				window.render(testTexture, sizeX, sizeY, pos.X, pos.Y, angle, center, flip);
				angle += 1.0f * deltaTime;
				sizeX += 2.0f * deltaTime;
				sizeY += 2.0f * deltaTime;
				center = { int(sizeX / 2), int(sizeY / 2) };
			}
			window.display();

			lastTime = currentTime;
		}
		window.cleanUp();
	}
}