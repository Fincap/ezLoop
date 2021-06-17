#pragma once

namespace ez {

	// Function pointers to GameLoop wrapper functions
	// These don't necessarily need to be instantiated.
	using fptr_wrapperFPS = int (GameBase::*)();
	using fptr_wrapperUPS = int (GameBase::*)();

	// Abstract base class defining functions called by the GameLoop.
	class GameBase
	{
	public:
		fptr_wrapperFPS getFPS;
		fptr_wrapperUPS getUPS;

	public:
		virtual void processInput() = 0;
		virtual void update() = 0;
		virtual void render(double extrapolation) = 0;
		virtual bool isOpen() = 0;

	};

}