#include "DXUT.h"
#include "Test.h"

#include "Engine/BaseLayer/Camera.h"
#include "Engine/BaseLayer/Time.h"

void Test::Init()
{
	LOAD(Texture, "TEST", "test.png");

	AC(Transform);
	AC(SpriteRenderer)->IsUI = false;

	renderer->SetTexture(FIND(Texture, "TEST"));
}

void Test::Update()
{
	if (Input::GetKeyPress(KeyCode::RightArrow))
		transform->Move(Vector3(10, 0, 0));

	if (Input::GetKeyPress(KeyCode::LeftArrow))
		transform->Move(Vector3(-10, 0, 0));

	if (Input::GetKeyPress(KeyCode::UpArrow))
		transform->Move(Vector3(0, -10, 0));

	if (Input::GetKeyPress(KeyCode::DownArrow))
		transform->Move(Vector3(0, 10, 0));
}

void Test::Render()
{
}

void Test::Destroy()
{
}
