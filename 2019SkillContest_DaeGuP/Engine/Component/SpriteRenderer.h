#pragma once
#include "Renderer.h"

class SpriteRenderer :
	public Renderer
{
private:
	Texture* renderTexture = nullptr;

public:
	virtual void SetTexture(Texture* texture);

	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Destroy() override;

	// Renderer��(��) ���� ��ӵ�
	virtual void Render() override;
};