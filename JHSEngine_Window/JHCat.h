#pragma once
#include "../JHSEngine_Source/JHGameObject.h"
namespace JH {
	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC  hdc) override;
	private:

	};
}

