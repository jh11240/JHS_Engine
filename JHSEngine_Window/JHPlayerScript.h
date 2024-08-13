#pragma once
#include "..\\JHSEngine_Source\\JHScript.h"

namespace JH
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack
		};
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update()   override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		virtual void OnColliderEnter(class Collider* other) override;
		virtual void OnColliderStay(class Collider* other) override;
		virtual void OnColliderExit(class Collider* other) override;

		void AttackEffect();

	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}
