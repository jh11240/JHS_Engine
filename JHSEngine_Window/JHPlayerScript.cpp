#include "JHPlayerScript.h"
#include "JHInput.h"
#include "JHTime.h"
#include "JHTransform.h" 
#include "JHGameObject.h"
#include "JHAnimator.h"
namespace JH {
	PlayerScript::PlayerScript():mState(PlayerScript::eState::SitDown) ,
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
		case JH::PlayerScript::eState::SitDown:
			sitDown();
			break;
		case JH::PlayerScript::eState::Walk:
			move();
			break;
		case JH::PlayerScript::eState::Sleep:
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
	void PlayerScript::sitDown()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = JH::PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");

		}
		if (Input::GetKey(eKeyCode::Left))
		{

			mState = JH::PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");


		}
		if (Input::GetKey(eKeyCode::Up))
		{

			mState = JH::PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");


		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = JH::PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");


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

			mState = JH::PlayerScript::eState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);

		}
	}
}