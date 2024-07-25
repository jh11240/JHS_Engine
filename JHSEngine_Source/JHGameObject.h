#pragma once
#include "CommonInclude.h"

namespace JH {

	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y) {mX = x; mY = y; }
		float GetPositionX() { return mX; };
		float GetPositionY() { return mY; };

	private:
		//object의 좌표
		float mX;
		float mY;

	};
}
