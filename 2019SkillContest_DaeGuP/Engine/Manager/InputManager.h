#pragma once
#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
private:
	bool bOldKeyState[256];
	bool bCurKeyState[256];

public:
	InputManager()
	{
	}
	virtual ~InputManager()
	{
	}

	__declspec(property(get = GetMousePos)) Vector2 MousePos;

	EventHandler<TouchEventArgs> OnLeftMouseClick;
	EventHandler<TouchEventArgs> OnRightMouseClick;

	EventHandler<bool> OnMouseWheelScroll;

	Vector2 GetMousePos()
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(DXUTGetHWND(), &pt);

		return Vector2((float)pt.x, (float)pt.y);
	}

	void InputUpdate();

	bool GetKeyDown(int key);
	bool GetkeyUp(int key);
	bool GetKeyPress(int key);

	void MouseScrollEvent(bool flag);
};

#define INPUT InputManager::GetInstance()