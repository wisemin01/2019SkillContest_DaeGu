#include "DXUT.h"
#include "Camera2D.h"

Matrix Camera2D::GetViewMatrix()
{
	return Matrix::View2D(position, Vector3::One, 0.0f);
}

Matrix Camera2D::GetProjectionMatrix()
{
	return Matrix::OrthoLH(Window::Width, -Window::Height, 0, 1);
}

Camera& Camera2D::SetMain()
{
	Camera::mainCamera = this;

	CAMERA.SetProjection(GetProjectionMatrix());

	return *this;
}

Camera2D& Camera2D::Create(const string& key)
{
	Camera2D* cam = new Camera2D();

	cameraContainer.insert(make_pair(key, cam));

	return *cam;
}
