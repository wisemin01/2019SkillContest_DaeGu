#include "DXUT.h"
#include "MainGame.h"

#include "IntroScene.h"

void MainGame::Update()
{
	INPUT.InputUpdate();
	SCENE.Update();
}

void MainGame::Render()
{
	RENDER.Render();
}

void MainGame::Release()
{
	SceneManager::Destroy();
	ObjectManager::Destroy();
	CollisionManager::Destroy();
	RenderManager::Destroy();
	InputManager::Destroy();
	CameraManager::Destroy();
	ResourceManager::Destroy();
}

void MainGame::OnResetDevice()
{
	RESOURCE.OnResetDevice();
}

void MainGame::OnLostDevice()
{
	RESOURCE.OnLostDevice();
}

void MainGame::Initialize()
{
	SCENE.AddScene("INTRO", new IntroScene());

	SCENE.ChangeScene("INTRO");
}
