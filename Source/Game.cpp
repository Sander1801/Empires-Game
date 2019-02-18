#include "../Headers/Game.h"
#include "../Headers/State Machine/Game/States/SplashScreenState.h"

// Standard C++
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <iostream>

constexpr float UPDATE_DELTA_TIME = 1.f / 30.f; // Update the gameplay with 30 frames per second,
												// a  nd draw the gameplay unlimited.

Game::Game()
{
}

Game::~Game()
{
} 

bool Game::OnEnter(Graphics* a_Graphics)
{ 
	m_GameDataRef = std::make_shared<GameData>();
	m_GameDataRef->graphics = a_Graphics;
	m_GameDataRef->machine.AddState(StateRef(new SplashScreenState(this->m_GameDataRef)), false);
}

bool Game::OnUpdate()
{	
	// FPS Info
	unsigned int uiFrames = 0;
	float fDeltatime = 0.0f;
	float fTotaltime = 0.0f;
	float fAccumulator = 0.0f;
	struct timeval TimeVal1, TimeVal2;
	struct timezone TimeZone;

	gettimeofday(&TimeVal1, &TimeZone);

	while (true)
	{
		// Check for state changes
		m_GameDataRef->machine.ProcessStateChanges();

		gettimeofday(&TimeVal2, &TimeZone);
		fDeltatime = (float)(TimeVal2.tv_sec - TimeVal1.tv_sec + (TimeVal2.tv_usec - TimeVal1.tv_usec) * 0.0000001f);
		TimeVal1 = TimeVal2;

		// Now work out how long that took
		fTotaltime += fDeltatime;
		fAccumulator += fDeltatime;
		uiFrames++;

		while (fAccumulator >= UPDATE_DELTA_TIME)
		{
			// Update the gameplay
			m_GameDataRef->machine.GetActiveState()->OnUpdate(UPDATE_DELTA_TIME);

			fAccumulator -= UPDATE_DELTA_TIME;
		}

		// Draw the gameplay
		m_GameDataRef->machine.GetActiveState()->OnDraw();

		if (fTotaltime > 1.0f)
		{
			//std::cout << "FPS: " << uiFrames / fTotaltime << std::endl;

			fTotaltime -= 1.0f;
			uiFrames = 0;
		}
	}
}