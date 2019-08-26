#include "DXUT.h"
#include "RenderManager.h"

#include "../Component/Renderer.h"
#include "../BaseLayer/SkyBox.h"
#include "../BaseLayer/Camera.h"

RenderManager::RenderManager()
{
	DXUTGetD3D9Device()->SetRenderState(D3DRS_LIGHTING, false);
}

RenderManager::~RenderManager()
{
	DXUTGetD3D9Device()->SetRenderState(D3DRS_LIGHTING, true);

	rendererList.clear();

	SkyBox::RemoveAll();
}

void RenderManager::Add(Renderer* renderer)
{
	rendererList.push_back(renderer);
}

void RenderManager::Remove(Renderer* renderer)
{
	rendererList.remove(renderer);
}

void RenderManager::AddUI(Renderer* renderer)
{
	UIList.push_back(renderer);
}

void RenderManager::RemoveUI(Renderer* renderer)
{
	UIList.remove(renderer);
}

void RenderManager::AddSprite(Renderer* renderer)
{
	spriteList.push_back(renderer);
}

void RenderManager::RemoveSprite(Renderer* renderer)
{
	spriteList.remove(renderer);
}

void RenderManager::Render()
{
	CAMERA.SetViewMatrix();

	// ================================================================
	// Draw 3D Objects
	// ================================================================
	if (Enable3D == true)
	{
		// SKY BOX RENDERING
		CAMERA.DrawSkyBox(true);

		// DXUTGetD3D9Device()->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

		for each (auto iter in rendererList)
		{
			iter->Render();
		}
	}


	// ================================================================
	// Draw 2D Sprite Objects
	// ================================================================
	if (Enable2D == true)
	{
		RESOURCE.RenderBegin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);

		// DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &Matrix::IdentityCoord);

		// DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &Matrix::_2DView(Vector3::Zero, Vector3::One, 0.0f));
		// DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &Matrix::OrthoLH(Window::Width, -Window::Height, 0, 1));

		for each (auto iter in spriteList)
		{
			iter->Render();
		}

		RESOURCE.RenderEnd();
	}


	// ================================================================
	// Draw 2D UI Objects
	// ================================================================
	if (EnableUI == true)
	{
		RESOURCE.RenderBegin(D3DXSPRITE_ALPHABLEND);

		// DRAW UI OBJECTS

		for each (auto iter in UIList)
		{
			iter->Render();
		}

		RESOURCE.RenderEnd();
	}
}
