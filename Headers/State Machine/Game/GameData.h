#ifndef __GameData_H_
#define __GameData_H_

#include "../Headers/Graphics/Graphics.h"
#include "../Headers/State Machine/Game/GameStateMachine.h"

struct GameData
{
	Graphics* graphics;
	GameStateMachine machine;
};

// Reference of GameData
typedef std::shared_ptr<GameData> GameDataRef;

#endif // __State_H_