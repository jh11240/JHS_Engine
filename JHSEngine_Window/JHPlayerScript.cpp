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
#include "JHResources.h"
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
		Cat* cat = object::Instantiate<Cat>
			(enums::eLayerType::Animal);

		CatScript* catSrc= cat->AddComponent<CatScript>();

		catSrc->SetPlayer(GetOwner());
		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
			catAnimator->CreateAnimation(L"DownWalk", catTex,
				Vector2(0.f, 0.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"RightWalk", catTex,
				Vector2(0.f, 32.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"UpWalk", catTex,
				Vector2(0.f, 64.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LeftWalk", catTex,
				Vector2(0.f, 96.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"SitDown", catTex,
				Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"Grooming", catTex,
				Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LayDown", catTex,
				Vector2(0.f, 192), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);


			catAnimator->PlayAnimation(L"SitDown", false);

			Transform* tr = GetOwner()->GetComponent<Transform>();

			cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

			Vector2 mousePos = Input::GetMousePosition();
			catSrc->mDest = mousePos;

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