#include "JHScript.h"
#include "JHCollider.h"
namespace JH {
	Script::Script()
		:Component(enums::eComponenetType::Script)
	{
	}
	Script::~Script()
	{
	}
	void Script::Initialize()
	{
	}

	void Script::Update()
	{
	}

	void Script::LateUpdate()
	{
	}

	void Script::Render(HDC hdc)
	{
	}
	void Script::OnColliderEnter(Collider* other)
	{
	}
	void Script::OnColliderStay(Collider* other)
	{
	}
	void Script::OnColliderExit(Collider* other)
	{
	}
}