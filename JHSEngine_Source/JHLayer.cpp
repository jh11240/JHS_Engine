#include "JHLayer.h"

namespace JH {

	Layer::Layer()
		:mType(enums::eLayerType::None)
		,mGameObjects{}
	{

	}
	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj != nullptr);
			delete gameObj;
			gameObj = nullptr;
		}

	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Render(hdc);
		}
	}
	void Layer::Destroy()
	{
		for (GameObjectIter iter =mGameObjects.begin();iter!= mGameObjects.end();)
		{
			if (*iter == nullptr)
				continue;
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead) 
			{
				GameObject* deathObj = (*iter);

				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}
			iter++;
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;
		mGameObjects.push_back(gameObject);
	}
}