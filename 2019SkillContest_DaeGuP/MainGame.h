#pragma once

class MainGame
{
public:
	void Update();
	void Render();
	void Release();

	void OnResetDevice();
	void OnLostDevice();

	void Initialize();
};
