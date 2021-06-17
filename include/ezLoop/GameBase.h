#pragma once

namespace ez {

	// Abstract base class defining functions called by the GameLoop.
	class GameBase
	{
	protected:
		int m_fps;
		int m_ups;

	public:	// These must be implemented by the child
		virtual void processInput() = 0;
		virtual void update() = 0;
		virtual void render(double extrapolation) = 0;
		virtual bool isOpen() = 0;

	public: // These cannot be reimplemented by the child
		virtual void setFPS(int fps) final { m_fps = fps; }
		virtual void setUPS(int ups) final { m_fps = ups; }

	};

}