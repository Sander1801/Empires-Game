#pragma once

#include "../Headers/Graphics/Graphics.h"
#include "../Headers/State Machine/Game/GameData.h"

class Game
{
public:
	Game();
	~Game();
	
	bool OnEnter(Graphics* Graph);
	bool OnUpdate();

private:
	GameDataRef m_GameDataRef; // State machine for switching between splash screen to main menu and et cetera.
};



