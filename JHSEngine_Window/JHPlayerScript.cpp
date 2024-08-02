#include "JHPlayerScript.h"
#include "JHInput.h"
#include "JHTime.h"
#include "JHTransform.h" 
#include "JHGameObject.h"
#include "JHAnimator.h"
#include "JHCat.h"
#include "JHCatScript.h"
#include "JHObject.h"
#include "JHResource.h"
namespace JH {
	PlayerScript::PlayerScript():mState(PlayerScript::eState::Idle) ,
		mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update() 
	{
		if(mAnimator == nullptr)
		mAnimator = GetOwner()->GetComponent<Animator>();
		switch (mState)
		{
		case JH::PlayerScript::eState::Idle:
			idle();
			break;
		case JH::PlayerScript::eState::Walk:
			move();
			break;
		case JH::PlayerScript::eState::Sleep:
			break;
		case JH::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case JH::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}
	
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::AttackEffect()
	{
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::MLeftBtn))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater",false);

			Vector2 mousePos = Input::GetMousePosition();

		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();

		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();

		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();

		}
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Up)
			|| Input::GetKeyUp(eKeyCode::Left) || Input::GetKeyUp(eKeyCode::Down)) {

			mState = JH::PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);

		}
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}