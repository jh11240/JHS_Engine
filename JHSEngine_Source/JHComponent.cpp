#include "JHComponent.h"
namespace JH {

	Component::Component(enums::eComponenetType type)
		:mOwner(nullptr)
		,mType(type)
	{

	}
	Component::~Component() {

	}


	 void Component::Initialize() {

	}
	void Component::Update() {

	}
	void Component::LateUpdate() {

	}
	void Component::Render(HDC hdc) {

	}
}