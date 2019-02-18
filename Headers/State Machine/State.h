#ifndef __State_H_
#define __State_H_

// Derived application class that wraps up all globals neatly
class State
{
public:
	virtual void OnEnter() = 0;
	virtual void OnUpdate(float a_deltaTime) = 0;
	virtual void OnDraw() = 0;
	virtual void OnExit() = 0;

	virtual void Pause() { }
	virtual void Resume() { }
};

#endif // __State_H_