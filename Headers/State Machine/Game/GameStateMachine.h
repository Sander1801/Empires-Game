#ifndef __StateMachine_H_
#define __StateMachine_H_

#include "../Headers/State Machine/State.h"
// Standard C++
#include <memory>
#include <stack>

typedef std::unique_ptr<State> StateRef;

class GameStateMachine
{
public:
	void AddState(StateRef a_newState, bool a_bIsReplacing = false, bool a_bIsReplacingAll = false);
	void RemoveState();
	// Run at start of each loop in Game.cpp
	void ProcessStateChanges();

	StateRef &GetActiveState();

private:
	// All states
	std::stack<StateRef> m_states;
	// New added state
	StateRef m_newState;

	bool m_bIsRemoving;
	bool m_bIsAdding;
	bool m_bIsReplacing;
	bool m_bIsReplacingAll;
};

#endif 