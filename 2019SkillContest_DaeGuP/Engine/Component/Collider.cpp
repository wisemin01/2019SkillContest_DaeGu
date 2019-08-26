#include "DXUT.h"
#include "Collider.h"

void Collider::Init()
{
	gameObject->collider = this;

	COLLISION.Add(this);
}

void Collider::Update()
{
	if (sphereData)
		sphereData->Translation(gameObject->transform->position);

	if (aabbData)
		aabbData->Translation(gameObject->transform->position);

	if (rectData)
		rectData->Translation(gameObject->transform->position);

	if (circleData)
		circleData->Translation(gameObject->transform->position);
}

void Collider::Destroy()
{
	if (gameObject->collider == this)
		gameObject->collider = nullptr;

	type = ColliderType::None;
	dType = DimensionType::None;

	COLLISION.Remove(this);

	SAFE_DELETE(sphereData);
	SAFE_DELETE(aabbData);
	SAFE_DELETE(rectData);
	SAFE_DELETE(circleData);
}

void Collider::SetAsSphere(float radius)
{
	if (sphereData)
	{
		SAFE_DELETE(sphereData);
	}

	sphereData = new SphereData(radius);

	sphereData->center = gameObject->transform->position;

	type = ColliderType::Sphere;
	dType = DimensionType::_3D;
}

void Collider::SetAsBox(float x, float y, float z)
{
	if (aabbData)
	{
		SAFE_DELETE(aabbData);
	}

	aabbData = new AABBData(x, y, z);

	aabbData->center = gameObject->transform->position;

	type = ColliderType::Box;
	dType = DimensionType::_3D;
}

void Collider::SetAsRectangle(float width, float height)
{
	if (rectData)
	{
		SAFE_DELETE(rectData);
	}

	rectData = new RectangleData(width, height);

	rectData->center = gameObject->transform->position;

	type = ColliderType::Rectangle;
	dType = DimensionType::_2D;
}

bool Collider::IsCollision(const Collider* col1, const Collider* col2)
{
	// 타입이 정해지지 않았으면 충돌을 검출하지 않음
	if (col1->type == ColliderType::None || 
		col2->type == ColliderType::None)
		return false;

	// 두 객체가 차원이 다르면 충돌을 검출하지 않음.
	if (col1->dType != col2->dType) // 2D, 3D
	{
		return false;
	}

	DimensionType dType = col1->dType;

	if (dType == DimensionType::_3D)
	{
		// 3D 충돌 검출
		
		if (col1->type == ColliderType::Sphere &&
			col2->type == ColliderType::Sphere)
			return SphereData::IsCollision(col1->sphereData, col2->sphereData);

		if (col1->type == ColliderType::Box &&
			col2->type == ColliderType::Box)
			return AABBData::IsCollision(col1->aabbData, col2->aabbData);

		if (col1->type == ColliderType::Box &&
			col2->type == ColliderType::Sphere)
			return MixData::IsCollision(col1->aabbData, col2->sphereData);

		if (col1->type == ColliderType::Sphere &&
			col2->type == ColliderType::Box)
			return MixData::IsCollision(col1->sphereData, col2->aabbData);
	}
	else if (dType == DimensionType::_2D)
	{
		// 2D 충돌 검출

		if (col1->type == ColliderType::Rectangle &&
			col2->type == ColliderType::Rectangle)
			return RectangleData::IsCollision(col1->rectData, col2->rectData);

		if (col1->type == ColliderType::Circle &&
			col2->type == ColliderType::Circle)
			return CircleData::IsCollision(col1->circleData, col2->circleData);
	}

	return false;
}

bool SphereData::IsCollision(const SphereData* a, const SphereData* b)
{
	Vector3 diff = b->center - a->center;
	float distance = Vector3::Length(diff);

	if (distance <= (a->radius + b->radius))
	{
		return true;
	}

	return false;
}

void SphereData::Translation(const Vector3& center)
{
	this->center = center;
}

bool AABBData::IsCollision(const AABBData* a, const AABBData* b)
{
	Vector3 amax = a->GetMax();
	Vector3 bmax = b->GetMax();

	Vector3 amin = a->GetMin();
	Vector3 bmin = b->GetMin();

	if (amax.x < bmin.x || amin.x > bmax.x) return 0;
	if (amax.y < bmin.y || amin.y > bmax.y) return 0;
	if (amax.z < bmin.z || amin.z > bmax.z) return 0;

	return true;
}

Vector3 AABBData::Intersect(const AABBData* a, const AABBData* b)
{
	Vector3 amax = a->GetMax();
	Vector3 bmax = b->GetMax();

	Vector3 amin = a->GetMin();
	Vector3 bmin = b->GetMin();

	Vector3 ret;

	for (int i = 0; i < 3; i++) {

		if (amax[i] > bmin[i])
			ret[i] = amax[i] - bmin[i];
		else if (bmin[i] > amax[i])
			ret[i] = bmin[i] - amax[i];
		
		if (bmin[i] > amin[i] && bmax[i] < amax[i])
			ret[i] = bmax[i] - bmin[i];
		else if (amin[i] > bmin[i] && amax[i] < bmax[i])
			ret[i] = amax[i] - amin[i];
		else
			ret[i] = 0;
	}

	return ret;
}

void AABBData::Translation(const Vector3& center)
{
	this->center = center;
}

bool MixData::IsCollision(const AABBData* a, const SphereData* b)
{
	Vector3 min = a->GetMin();
	Vector3 max = a->GetMax();

	Vector3 sphereC = b->center;
	float radius = b->radius;

	if (max.x < (sphereC.x - radius) || min.x > (sphereC.x + radius)) return false;
	if (max.y < (sphereC.y - radius) || min.y > (sphereC.y + radius)) return false;
	if (max.z < (sphereC.z - radius) || min.z > (sphereC.z + radius)) return false;

	return true;
}

bool MixData::IsCollision(const SphereData* a, const AABBData* b)
{
	return IsCollision(b, a);
}

void RectangleData::Translation(const Vector3& position)
{
	center = position;
}

bool RectangleData::IsCollision(const RectangleData* a, const RectangleData* b)
{
	return false;
}

bool CircleData::IsCollision(const CircleData* a, const CircleData* b)
{
	Vector3 diff = b->center - a->center;
	float distance = Vector3::Length(diff);

	if (distance <= (a->radius + b->radius))
	{
		return true;
	}

	return false;
}

void CircleData::Translation(const Vector3& position)
{
	center = position;
}
