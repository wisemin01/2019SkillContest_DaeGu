#pragma once

#include "Engine/BaseLayer/Scene.h"

class IntroScene :
	public Scene
{
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Destroy() override;
};

