#include "../Headers/State Machine/Game/States/SplashScreenState.h"
#include "../Headers/State Machine/Game/States/GameState.h"
// Standard C++
#include <iostream>

SplashScreenState::SplashScreenState(GameDataRef a_GameStateData) :
	m_GameStateData(a_GameStateData)
{
}

void SplashScreenState::OnEnter()
{
}

void SplashScreenState::OnUpdate(float a_fDeltaTime)
{
	m_GameStateData->machine.AddState(StateRef(new GameState(m_GameStateData)), true);
}

void SplashScreenState::OnDraw()
{
}

void SplashScreenState::OnExit()
{
}
