#pragma once

namespace ez {

	// Abstract base class defining functions called by the GameLoop.
	class GameBase
	{
	protected:
		// Amount of frames rendered per second.
		int m_fps;
		// Number of updates completed per second.
		int m_ups;

	public:	// These must be implemented by the child.
		// Function responsible for processing game input.
		virtual void processInput() = 0;

		// Function responsible for updating the game state.
		virtual void update() = 0;

		// Function responsible for drawing the game to the screen.
		virtual void render(double extrapolation) = 0;

		// Function that controls the execution of the game loop.
		// When this returns false, it signals the loop controller to exit the loop.
		virtual bool isOpen() = 0;

	public: // These cannot be reimplemented by the child.
		// Report the current frames rendered per second to game object.
		virtual void setFPS(int fps) final { m_fps = fps; }

		// Report the current updates completed per second to game object.s
		virtual void setUPS(int ups) final { m_fps = ups; }

	};

}