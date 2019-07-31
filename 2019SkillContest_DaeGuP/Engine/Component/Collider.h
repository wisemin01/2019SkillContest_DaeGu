#pragma once
#include "Component.h"

class Matrix;
class Vector3;


struct SphereData
{
	SphereData() {}
	SphereData(float radius) : length(radius) {}

	Vector3 center;
	float length;

	static bool IsCollision(const SphereData* a, const SphereData* b);

	void Translation(const Vector3& center);
};

struct AABBData
{
	AABBData() {}
	AABBData(float x, float y, float z)
		: localMin(-x / 2.f, -y / 2.f, -z / 2.f), localMax(x / 2.f, y / 2.f, z / 2.f) {}

	Vector3 localMin;
	Vector3 localMax;

	Vector3 center;

	Vector3 GetMin() const { return localMin + center; }
	Vector3 GetMax() const { return localMax + center; }

	static bool IsCollision(const AABBData* a, const AABBData* b);
	static Vector3 Intersect(const AABBData* a, const AABBData* b);

	void Translation(const Vector3& center);
};

struct MixData
{
	// OTHER MIX COLLISION DATA

	static bool IsCollision(const AABBData* a, const SphereData* b);
	static bool IsCollision(const SphereData* a, const AABBData* b);
};

struct RectangleData
{
public:
	RectangleData(long w, long h) 
	{
		SetRect(&range, -w / 2, -h / 2, w / 2, h / 2);
	}

	RECT range;
	Vector3 center;

	void Translation(const Vector3& position);
};

class Collider :
	public Component
{
	enum class ColliderType: int
	{
		None,
		Box,
		Sphere,
		Rectangle,
		Circle
	};
	enum class DimensionType : int
	{
		None,
		_2D,
		_3D
	};
public:

	SphereData* sphereData = nullptr;
	AABBData* aabbData = nullptr;
	RectangleData* rectData = nullptr;

	ColliderType type = ColliderType::None;
	DimensionType dType = DimensionType::None;

	__declspec(property(get = GetTag)) string Tag;

	bool isTrigger = false;

public:
	// Component��(��) ���� ��ӵ�
	virtual void Init();
	virtual void Update();
	virtual void Destroy();

	void SetAsSphere(float radius);
	void SetAsBox(float x, float y, float z);
	void SetAsRectangle(float width, float height);

	string GetTag() { return gameObject->Tag; }

public:
	static bool IsCollision(const Collider* col1, const Collider* col2);
};

