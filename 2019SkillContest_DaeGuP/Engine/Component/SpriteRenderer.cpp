#include "DXUT.h"
#include "SpriteRenderer.h"

void SpriteRenderer::SetTexture(Texture* texture)
{
	renderTexture = texture;
}

void SpriteRenderer::Init()
{
	__super::Init();
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::Destroy()
{
	__super::Destroy();
}

void SpriteRenderer::Render()
{
	if (renderBegin) renderBegin();

	const Matrix& world = gameObject->transform->World;

	RESOURCE.SetSpriteTransform(world);
	RESOURCE.SpriteDraw(renderTexture, Color(1, 1, 1, 1));

	if (renderEnd) renderEnd();
}
