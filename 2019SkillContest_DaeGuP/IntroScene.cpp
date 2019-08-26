#include "DXUT.h"
#include "IntroScene.h"

#include "Engine/BaseLayer/Camera2D.h"
#include "Test.h"

void IntroScene::Init()
{
	Camera2D::Create("Main").SetMain();

	Instance(Test);
}

void IntroScene::Update()
{
	OBJECT.Update();
}

void IntroScene::Destroy()
{
	OBJECT.Reset();
}
