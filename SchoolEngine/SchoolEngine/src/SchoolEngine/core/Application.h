#pragma once

namespace SchoolEngine {
	class Application {
	public:
		Application();
		~Application();

		void run();
	private:
		void initialize();
	};
}