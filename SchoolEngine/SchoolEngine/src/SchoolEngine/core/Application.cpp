#include "Application.h"
#include "Window.h"
#include "../util/Factory.h"
#include "../util/Point.h"
#include "../util/Vector2.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include<iostream>
#include "../components/Angle.h"
#include "../systems/Move.h"
#include "../systems/Accelerate.h"

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


		// Initialization logic below

		for (int i = 0; i < 1; i++) {
			entt::entity e = makeSquare(_reg, Vector2{32.0f, 32.0f});
		}

		auto view = _reg.view<Point>();

		int x = 50;
		int y = 300;
		const int adder = 64;

		for (const entt::entity entity : view) {
			Point& pos = view.get<Point>(entity);
			pos.X = x;
			pos.Y = y;

			x += adder;
		}

	}

	void Application::handleEvents() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				_running = false;
				break;
			default:
				break;
			}
		}
	}

	void Application::update(float deltaTime) {
		accelerate(_reg, deltaTime);
		move(_reg, deltaTime);
	}

	void Application::run() {
		// Creates a window
		Window window("Test", 1366, 720);

		SDL_Texture* testTexture = window.loadTexture("Content/Textures/Sprites/TestSquareRed.png"); // TODO: REMOVE
		
		// Timing variables
		Uint32 old_time, current_time;
		float ftime;

		// Need to initialize this here for event loop to work
		current_time = SDL_GetTicks();

		// Application Loop runs until event == SDL_QUIT
		_running = true;
		while (_running) {
			handleEvents();

			// Update the timing information
			old_time = current_time;
			current_time = SDL_GetTicks();
			ftime = (current_time - old_time) / 1000.0f;

			update(ftime);

			auto view = _reg.view<Point, Vector2, Angle>();

			window.clear();
			for (const entt::entity entity : view) {
				Point& pos = view.get<Point>(entity);
				Vector2& size = view.get<Vector2>(entity);
				Angle& angle = view.get<Angle>(entity);

				SDL_RendererFlip flip = SDL_FLIP_NONE;
				SDL_Point center = { int(size.X / 2), int(size.Y / 2) };

				window.render(testTexture, size.X, size.Y, pos.X, pos.Y, angle.Angle, center, flip);
			}
			window.display();
		}
		window.cleanUp();
	}
}