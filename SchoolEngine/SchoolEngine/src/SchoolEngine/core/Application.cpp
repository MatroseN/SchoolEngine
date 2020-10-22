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

		for (int i = 0; i < 20; i++) {
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

	void Application::calculateDeltaTime() {
		_currentTime = SDL_GetTicks();
		_lastTime = _currentTime;
		_deltaTime = (_currentTime - _lastTime) / 1000.0f;
	}

	void Application::handleEvents() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				break;
			default:
				break;
			}
		}
	}

	void Application::update(float deltaTime) {

	}

	void Application::run() {
		// Creates a window
		Window window("Test", 1366, 720);

		SDL_Texture* testTexture = window.loadTexture("Content/Textures/Sprites/TestSquareRed.png"); // TODO: REMOVE

		// Application Loop runs until event == SDL_QUIT
		_running = true;
		while (_running) {
			handleEvents();

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

			_lastTime = _currentTime;
		}
		window.cleanUp();
	}
}