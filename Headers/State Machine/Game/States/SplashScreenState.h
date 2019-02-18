#ifndef __SplashScreenState_H_
#define __SplashScreenState_H_

#include "../Headers/State Machine/State.h"
#include "../Headers/State Machine/Game/GameData.h"

class SplashScreenState : public State
{
public:
	SplashScreenState(GameDataRef a_GameStateData);

	void OnEnter();
	void OnUpdate(float a_fDeltaTime);
	void OnDraw();
	void OnExit();

private:
	GameDataRef m_GameStateData;
};

#endif