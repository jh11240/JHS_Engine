#pragma once
#include "JHEntity.h"

namespace JH {
	//전방 선언
	class GameObject;

	class Component :public Entity
	{
	public:

		Component(enums::eComponenetType type);
		~Component();


		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() {
			return mOwner;
		}
		enums::eComponenetType GetType() { return mType; }
	private:
		GameObject* mOwner;
		enums::eComponenetType mType;
	};

}
