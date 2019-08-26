#pragma once

class Camera
{
	// Member : Shake Power, Shake Time
	using ShakeInfo = std::tuple<float, float>;

	friend class CameraManager;
	friend class SkyBox;

	ShakeInfo shakeInfo;
	
public:
	Camera() {}
	Camera(Vector3 pos, Vector3 look = Vector3(0.f, 0.f, 0.f), Vector3 up = Vector3(0.f, 1.f, 0.f))
		: position(pos), lookAt(look), up(up) {}

	Vector3 position	= Vector3::Zero;
	Vector3 lookAt		= Vector3::Zero;
	Vector3 up			= Vector3::Up;

	__declspec(property(get = GetForward))	Vector3 Forward;
	__declspec(property(get = GetBack))		Vector3 Back;
	__declspec(property(get = GetRight))	Vector3 Right;
	__declspec(property(get = GetLeft))		Vector3 Left;
	__declspec(property(get = GetUp))		Vector3 Up;
	__declspec(property(get = GetDown))		Vector3 Down;

	__declspec(property(get = GetViewMatrix))		Matrix ViewMatrix;
	__declspec(property(get = GetProjectionMatrix)) Matrix ProjectionMatrix;

	virtual void Update();

	virtual Matrix GetViewMatrix();
	virtual Matrix GetProjectionMatrix();

	virtual Camera& SetMain();

	Camera& SetPosition(Vector3 position);
	Camera& SetLookAt(Vector3 lookAt);
	Camera& SetUp(Vector3 up);

	Vector3 GetForward();
	Vector3 GetBack();
	Vector3 GetRight();
	Vector3 GetLeft();
	Vector3 GetUp();
	Vector3 GetDown();

protected:
	// STATIC FIELD

	static Camera* mainCamera;

public:

	static Camera* GetMainCamera() { return mainCamera; }

	static Camera& Create(const string& key);
	static Camera& Find(const string& key);
	static void Remove(const string& key);
	static void RemoveAll();

protected:
	static std::map<string, Camera*> cameraContainer;
};