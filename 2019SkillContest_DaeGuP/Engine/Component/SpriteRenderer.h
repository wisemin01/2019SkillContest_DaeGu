#pragma once
#include "Renderer.h"

class SpriteRenderer :
	public Renderer
{
private:
	Texture* renderTexture = nullptr;

	bool isCenterRender = true;
	bool isUIRender = false;

public:
	virtual void SetTexture(Texture* texture);

	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Destroy() override;

	// Renderer을(를) 통해 상속됨
	virtual void Render() override;

	bool GetIsUIRender();
	void SetIsUIRender(bool value);

	__declspec(property(get = GetIsUIRender, put = SetIsUIRender)) bool IsUI;
};