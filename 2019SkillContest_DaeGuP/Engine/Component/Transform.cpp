#include "DXUT.h"
#include "Transform.h"

void Transform::Rotate(Vector3 degree)
{
	_rotation *= Quaternion::Rotation(degree.ToRadian());
}

void Transform::Move(Vector3 plus)
{
	_position += plus;
}

Matrix Transform::GetWorldMatrix()
{
	Matrix world;

	world = Matrix::Scaling(_scale)
		* Matrix::RotationQuaternion(_rotation)
		* Matrix::Translation(_position);
	
	if (parents)
		world *= parents->World;

	return world;
}

Matrix Transform::GetWorldMatrix2D()
{
	Matrix world2D;

	world2D = Matrix::Scaling(_scale)
		* Matrix::RotationZ(_rotation.z)
		* Matrix::Translation(_position);

	if (parents)
		world2D *= parents->World2D;

	return world2D;
}

Matrix Transform::GetRotationMatrix()
{
	return Matrix::RotationQuaternion(rotation);
}

void Transform::Init()
{
	gameObject->transform = this;

	position = Vector3::Zero;
	scale = Vector3::One;
	rotation = Quaternion::Identity;
}

void Transform::Update()
{
}

void Transform::Destroy()
{
	if (gameObject->transform == this)
		gameObject->transform = nullptr;
}

void Transform::AddChild(Transform* t)
{
	if (t == nullptr)
		return;

	t->parents = this;
}

void Transform::RemoveChild(Transform* t)
{
	if (t == nullptr)
		return;

	if (t->parents == this)
		t->parents = nullptr;
}
