#pragma once
#include "Engine/BaseLayer/GameObject.h"

class Test :
	public GameObject
{
public:
	// GameObject을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
};

