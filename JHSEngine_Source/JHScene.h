#pragma once
#include"JHEntity.h"
#include"JHGameObject.h"
#include "JHLayer.h"

namespace JH {

	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj ,const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) {return mLayers[(UINT)type]; }

	private:
		//std::vector<GameObject*> mGameObjects;
		std::vector<Layer*> mLayers;
	};
}

