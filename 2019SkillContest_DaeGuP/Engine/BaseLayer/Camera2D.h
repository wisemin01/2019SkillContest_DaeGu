#pragma once
#include "Camera.h"

class Camera2D :
	public Camera
{
public:
	virtual Matrix GetViewMatrix();
	virtual Matrix GetProjectionMatrix();

	virtual Camera& SetMain();

public:
	static Camera2D& Create(const string& key);
};

