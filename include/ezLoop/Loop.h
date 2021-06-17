#pragma once

#include "GameBase.h"
#include "TimeUtil.h"

namespace ez {

	class Loop {
	private:
		double m_previous, m_fpsTimer, m_lag;
		int m_frames, m_updates;
		int m_fps, m_ups;
		int m_msPerUpdate;

		GameBase* m_game;

	public:
		Loop() :
			m_previous(ez::getCurrentTime()),
			m_fpsTimer(ez::getCurrentTime()),
			m_lag(0.0),
			m_frames(0),
			m_updates(0),
			m_fps(0),
			m_ups(0),
			m_msPerUpdate(1000 / 120),
			m_game(nullptr) {}

		void setGame(GameBase*);
		void begin();
		int getFPS();
		int getUPS();
	};

}