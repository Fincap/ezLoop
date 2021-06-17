/*

This is the minimal code required to use the library.
The expect output is console spam for 5 seconds.
The output will alternate between processing input and rendering, with the
occasional updating sprinkled in.

*/

#include "ezLoop/Loop.h"

#include <iostream>

// Create basic child class of GameBase
class Game : public ez::GameBase {
private:
	double m_timeStarted;

public:
	void processInput() override {
		std::cout << "Processing input..." << std::endl;
	}
	void update() override {
		std::cout << "Updating..." << std::endl;
	}
	void render(double) override {
		std::cout << "Rendering..." << std::endl;
	}
	bool isOpen() override {
		return ez::getCurrentTime() < m_timeStarted + 5000; // End after 5 seconds
	}

public:
	Game() : m_timeStarted(ez::getCurrentTime()) {}

};

int main() {

	// Create game and loop
	Game game;
	ez::Loop loop(game);

	// Begin loop
	loop.begin();

	return 0;

}