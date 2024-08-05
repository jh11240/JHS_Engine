#pragma once
#include "JHComponent.h"
#include "JHLayer.h"
#include "JHGameObject.h"
#include "JHSceneManager.h"
#include "JHScene.h"

namespace JH::object
{
	template <typename T>
	static T* Instantiate(JH::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}
	template <typename T>
	static T* Instantiate(JH::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* obj)
	{
		obj->Death();
	}
}