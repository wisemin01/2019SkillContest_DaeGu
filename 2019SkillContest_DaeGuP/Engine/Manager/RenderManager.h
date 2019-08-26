#pragma once
#include "Singleton.h"

class Renderer;
class RenderManager :
	public Singleton<RenderManager>
{
private:
	std::list<Renderer*> rendererList;
	std::list<Renderer*> spriteList;
	std::list<Renderer*> UIList;
public:

	bool Enable3D = true;
	bool Enable2D = true;
	bool EnableUI = true;

	RenderManager();
	~RenderManager();

	void Add(Renderer* renderer);
	void Remove(Renderer* renderer);

	void AddUI(Renderer* renderer);
	void RemoveUI(Renderer* renderer);

	void AddSprite(Renderer* renderer);
	void RemoveSprite(Renderer* renderer);

	void Render();
};

#define RENDER RenderManager::GetInstance()