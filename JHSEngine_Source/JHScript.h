#pragma once
#include"JHComponent.h"

namespace JH
{
	class Script : public Component
	{
	public:
		Script();
		~Script();
		void Initialize() override;
		void Update()   override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


		virtual void OnColliderEnter(class Collider* other);
		virtual void OnColliderStay(class Collider* other);
		virtual void OnColliderExit(class Collider* other);

	private:

	};
}
