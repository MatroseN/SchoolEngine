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

		entt::registry _reg;
		bool _running = false;
	};
}