#pragma once

class MainGame
{
public:
	void Initialize();
	void Update();
	void Render();
	void Release();

	void OnResetDevice();
	void OnLostDevice();
};
