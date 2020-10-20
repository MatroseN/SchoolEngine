#include "core/Application.h"
#include <stdio.h>
#include <SDL.h>
#include <iostream>

// The entry point for the application
int main(int argc, char* argv[]) {

	std::cout << "Start..." << std::endl;
	SchoolEngine::Application app; // Instanciates an application
	app.run(); // Runds the application

	std::cin.get();
	return 0;
}