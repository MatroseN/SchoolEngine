#include "core/Application.h"
#include <stdio.h>
#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {

	std::cout << "Start..." << std::endl;

	SchoolEngine::Application app;
	app.run();

	return 0;
}