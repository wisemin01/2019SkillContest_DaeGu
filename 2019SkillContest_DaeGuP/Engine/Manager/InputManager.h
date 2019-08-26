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

static class Input
{
public:
	static bool GetKeyDown(int key);
	static bool GetKeyUp(int key);
	static bool GetKeyPress(int key);
};

static class KeyCode
{
public:
	static const int Q = 'Q';
	static const int W = 'W';
	static const int E = 'E';
	static const int R = 'R';
	static const int T = 'T';
	static const int Y = 'Y';
	static const int U = 'U';
	static const int I = 'I';
	static const int O = 'O';
	static const int P = 'P';
	static const int A = 'A';
	static const int S = 'S';
	static const int D = 'D';
	static const int F = 'F';
	static const int G = 'G';
	static const int H = 'H';
	static const int J = 'J';
	static const int K = 'K';
	static const int L = 'L';
	static const int Z = 'Z';
	static const int X = 'X';
	static const int C = 'C';
	static const int V = 'V';
	static const int B = 'B';
	static const int N = 'N';
	static const int M = 'M';

	static const int Minus = '-';
	static const int Plus = '+';
	static const int Slash = '/';
	static const int Comma = ',';
	static const int Period = '.';
	static const int Colon = ':';
	static const int Semicolon = ';';
	static const int Less = '<';
	static const int Equals = '=';
	static const int Greater = '>';
	static const int Question = '?';
	static const int At = '@';

	static const int Enter = VK_RETURN;
	static const int Space = VK_SPACE;
	static const int Backspace = VK_BACK;
	static const int LeftShift = VK_LSHIFT;
	static const int RightShift = VK_RSHIFT;
	static const int Control = VK_CONTROL;
	static const int Escape = VK_ESCAPE;
	static const int Insert = VK_INSERT;
	static const int Home = VK_HOME;
	static const int End = VK_END;
	
	static const int F1 = VK_F1;
	static const int F2 = VK_F2;
	static const int F3 = VK_F3;
	static const int F4 = VK_F4;
	static const int F5 = VK_F5;
	static const int F6 = VK_F6;
	static const int F7 = VK_F7;
	static const int F8 = VK_F8;
	static const int F9 = VK_F9;
	static const int F10 = VK_F10;
	static const int F11 = VK_F11;
	static const int F12 = VK_F12;
	static const int F13 = VK_F13;
	static const int F14 = VK_F14;
	static const int F15 = VK_F15;

	static const int LeftArrow = VK_LEFT;
	static const int UpArrow = VK_UP;
	static const int RightArrow = VK_RIGHT;
	static const int DownArrow = VK_DOWN;

	static const int Mouse0 = VK_LBUTTON;
	static const int Mouse1 = VK_RBUTTON;
	static const int Mouse2 = VK_MBUTTON;
	static const int Mouse3 = VK_XBUTTON1;
	static const int Mouse4 = VK_XBUTTON2;
};

#define INPUT InputManager::GetInstance()