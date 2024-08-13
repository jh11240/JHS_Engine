#include "JHCollider.h"
#include "JHScript.h"
#include "JHGameObject.h"


namespace JH {
	UINT32 Collider::mCollisionID =1;

	Collider::Collider(enums::eColliderType type)
		:Component(enums::eComponenetType::Collider)
		, mId(mCollisionID++)
		, mSize(Vector2::One)
		, mType(type)
	{
	}
	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
	}
	void Collider::Update()
	{
	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render(HDC hdc)
	{
	}
	void Collider::OnColliderEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnColliderEnter(other);
	}
	void Collider::OnColliderStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnColliderStay(other);
	}
	void Collider::OnColliderExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnColliderExit(other);
	}
}