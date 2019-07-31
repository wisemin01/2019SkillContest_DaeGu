#pragma once
#include "Renderer.h"

class SpriteRenderer :
	public Renderer
{
private:
	Texture* renderTexture = nullptr;

public:
	virtual void SetTexture(Texture* texture);

	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Destroy() override;

	// Renderer을(를) 통해 상속됨
	virtual void Render() override;
};