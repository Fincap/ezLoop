#pragma once

#include "GameBase.h"
#include "TimeUtil.h"

namespace ez {

	class Loop {
	private:
		double m_previous, m_fpsTimer, m_lag;
		int m_frames, m_updates;
		int m_msPerUpdate;

		GameBase& m_game;

	public:
		Loop(GameBase& game, int msPerUpdate = 1000 / 120) :
			m_previous(ez::getCurrentTime()),
			m_fpsTimer(ez::getCurrentTime()),
			m_lag(0.0),
			m_frames(0),
			m_updates(0),
			m_msPerUpdate(msPerUpdate), // 1000 / 120 is used to represent 120ms delay
			m_game(game) {}

		// Commences the game loop.
		void begin();
	};

}