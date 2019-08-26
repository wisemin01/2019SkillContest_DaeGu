#include "DXUT.h"
#include "SpriteRenderer.h"

#include "../BaseLayer/Texture.h"

void SpriteRenderer::SetTexture(Texture* texture)
{
	renderTexture = texture;
}

void SpriteRenderer::Init()
{
	gameObject->renderer = this;

	if (isUIRender)
		RENDER.AddUI(this);
	else
		RENDER.AddSprite(this);
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::Destroy()
{
	if (gameObject->renderer == this)
		gameObject->renderer = nullptr;

	if (isUIRender)
		RENDER.RemoveUI(this);
	else
		RENDER.RemoveSprite(this);
}

void SpriteRenderer::Render()
{
	if (renderBegin) renderBegin();

	const Matrix& world = gameObject->transform->World2D;

	RESOURCE.SetSpriteTransform(world);
	RESOURCE.SpriteDraw(renderTexture, Color(1, 1, 1, 1), 
		isCenterRender ? Vector3(renderTexture->GetWidth() / 2, renderTexture->GetHeight() / 2, 0) : Vector3::Zero);

	if (renderEnd) renderEnd();
}

bool SpriteRenderer::GetIsUIRender()
{
	return isUIRender;
}

void SpriteRenderer::SetIsUIRender(bool value)
{
	if (value == isUIRender)
		return;

	// UI 로 전환됬다면.
	if (value == true)
	{
		RENDER.RemoveSprite(this);
		RENDER.AddUI(this);
	}
	// SPRITE 로 전환됬다면.
	else
	{
		RENDER.RemoveUI(this);
		RENDER.AddSprite(this);
	}

	isUIRender = value;
}
