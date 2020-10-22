#pragma once
#include <entt.hpp>

namespace SchoolEngine {
	// Driver that creates the application
	class Application {
	public:
		Application();
		~Application();

		// Where the application is specified (application loop)
		void run();
	private:
		// Initializes the application with what it needs to be able to run
		void initialize();
		void update(float deltaTime);
		void handleEvents();
		void calculateDeltaTime();

		entt::registry _reg;
		float _deltaTime;
		float _currentTime;
		float _lastTime;
		bool _running;
	};
}