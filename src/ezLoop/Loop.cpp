#include "ezLoop/Loop.h"

void ez::Loop::setGame(GameBase* game)
{
	m_game = game;
}

void ez::Loop::begin()
{
	while (m_game->isOpen()) {

		double current = ez::getCurrentTime();
		double elapsed = current - m_previous;
		m_previous = current;
		m_lag += elapsed;

		// Process input
		m_game->processInput();

		while (m_lag >= m_msPerUpdate) {
			// Update game state
			m_game->update();

			m_lag -= m_msPerUpdate;
			m_updates++;
		}

		// Render
		m_game->render(m_lag / m_msPerUpdate);
		m_frames++;

		// Update FPS counter
		if (ez::getCurrentTime() - m_fpsTimer > 1000) {
			m_fpsTimer += 1000;

			m_game->setFPS(m_frames);
			m_game->setUPS(m_updates);

			m_frames = 0;
			m_updates = 0;
		}

	}
}
