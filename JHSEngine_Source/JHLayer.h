#pragma once
#include "JHEntity.h"
#include "CommonInclude.h"
#include "JHGameObject.h"

namespace JH 
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);


	private:
			enums::eLayerType mType;
			std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;

}
