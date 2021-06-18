# ezLoop

A simple C++  library that creates an efficient and reliable game loop. The implementation
was designed with SFML in mind, however it is totally library-agonistic and can be used with
any graphics library.

The looper takes care of all the boilerplate required to set up an efficient game loop, and can
be implemented using a minimal amount of code.

The library separates the the loop into three distinct phases:
1. Input processing
2. Game state updating
3. Rendering

Rendering and input processing will occur as frequently as possible, whereas the update phase will
occur at a customisable fixed interval.

### Installation

Simply clone the repository and compile it yourself, or download one of the zip files from the
releases section. Add the 'include' directory to the additional includes, and make sure that the
linker is including the 'lib' directory and the 'ezloop.lib' file.

### How to use

In order to interface with the `Loop`, the abstract base class `GameBase` will need to be
implemented in a new class, and that class passed into the `Loop` constructor.

A minimal example is shown below.

```
#include <ezLoop/Loop.h>

// Implement the GameBase interface
class Game : public GameBase {
public:
	void processInput() override {
		// process input
	}
	void update() override {
		// update game state
	}
	void render(double extrapolation) override {
		// render game
	}
	bool isOpen() override {
		// when returns false, exit loop
	}
	
}

int main(int argc, char** argv) {
	// Create game and loop
	Game game;
	ez::Loop loop(game);

	// Begin loop
	loop.begin();

	return 0;
}

```

A runnable example can be found [here](examples/minimal.cpp)

Game initialisation and logic can then be placed in the respective GameBase overrides.

Render will have one parameter, representing the extrapolation of the current frame.
This value represents at which percentage in between updates the current frame was rendered.
For example a value of `0.23f` would represent that the frame was rendered 23% of the way
between updates. This can be optionally used to create smooth rendering of moving objects
on the screen.

### Contribution

Accepting any and all contributes, feedback, advice, etc.

If there's an even better way of implementing this, I would love to learn.
