#include "../Headers/State Machine/Game/GameStateMachine.h"
// Standard C++
#include <iostream>

void GameStateMachine::AddState(StateRef a_newState, bool a_bIsReplacing, bool a_bIsReplacingAll)
{
	m_bIsRemoving = false;
	m_bIsAdding = true;
	m_bIsReplacing = a_bIsReplacing;
	m_bIsReplacingAll = a_bIsReplacingAll;

	// Set new state
	m_newState = std::move(a_newState);
}

void GameStateMachine::RemoveState()
{
	m_bIsRemoving = true;
}

void GameStateMachine::ProcessStateChanges()
{
	// State is not empty and needs to be removed
	if (m_bIsRemoving && !m_states.empty())
	{
		// Remove latest state
		m_states.top()->OnExit();
		m_states.pop();

		// There are more states
		if (!m_states.empty())
		{
			// Resume latest state
			m_states.top()->Resume();
		}
		// Stop removing
		m_bIsRemoving = false;
	}

	if (m_bIsAdding)
	{
		// State is not empty
		if (!m_states.empty())
		{
			// Replace all states
			if (m_bIsReplacingAll)
			{
				while (!m_states.empty())
				{
					m_states.top()->OnExit();
					m_states.pop();
				}
			}
			// Replace previous state
			else if (m_bIsReplacing)
			{
				m_states.top()->OnExit();
				m_states.pop();
			}
			// Set previous state on pause
			else
			{
				m_states.top()->Pause();
			}
		}

		// Push new state
		m_states.push(std::move(m_newState));
		// Get last inserted element and call OnEnter
		m_states.top()->OnEnter();
		// Stop adding the state
		m_bIsAdding = false;
	}
}

StateRef &GameStateMachine::GetActiveState()
{
	// Get last inserted element
	return m_states.top();
}