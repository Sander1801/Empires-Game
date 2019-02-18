#ifndef __GameState_H_
#define __GameState_H_

#include "../Headers/State Machine/State.h"
#include "../Headers/State Machine/Game/GameData.h"

class GameState : public State
{
public:
	GameState(GameDataRef a_GameStateData);

	void OnEnter();
	void OnUpdate(float a_fDeltaTime);
	void OnDraw();
	void OnExit();

private:
	GameDataRef m_GameStateData;
};

#endif