#include "JHTransform.h"

namespace JH {

	Transform::Transform()
		: Component(enums::eComponenetType::Transform)
		,mScale(Vector2::One)
		,mRotation(0.f)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
	}

	void Transform::LateUpdate()
	{
	}

	void Transform::Render(HDC hdc)
	{
	}
}