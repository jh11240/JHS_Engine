#include "JHGameObject.h"
#include "JHInput.h"
#include "JHTransform.h"
namespace JH {
	GameObject::GameObject() :
		mComponents{}, mState(eState::Active)
	{
		mComponents.resize((UINT)enums::eComponenetType::End);
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents) {
			if (comp == nullptr)
				continue;  
			delete comp;
			comp = nullptr;
		}
	}
	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{

		for (Component* comp : mComponents)
		{

			if (comp == nullptr)
				continue;
			comp->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Render(hdc);
		}
	}
	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();

	}
}
