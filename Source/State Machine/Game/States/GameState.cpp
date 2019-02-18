#include "../Headers/State Machine/Game/States/GameState.h"
// Standard C++
#include <iostream>

GameState::GameState(GameDataRef a_GameStateData) :
	m_GameStateData(a_GameStateData)
{
}

void GameState::OnEnter()
{
}

void GameState::OnUpdate(float a_fDeltaTime)
{
}

void GameState::OnDraw()
{
	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// After our draw we need to swap buffers to display on screen
	eglSwapBuffers(m_GameStateData->graphics->state.display, m_GameStateData->graphics->state.surface);
}

void GameState::OnExit()
{ 
}