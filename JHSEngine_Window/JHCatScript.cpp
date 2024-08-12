#include "JHCatScript.h"
#include "JHInput.h"
#include "JHTime.h"
#include "JHTransform.h" 
#include "JHGameObject.h"
#include "JHAnimator.h"
#include "JHObject.h"

namespace JH {
	CatScript::CatScript() :mState(CatScript::eState::SitDown),
		mAnimator(nullptr)
		, mTime(0.0f)
		,mDeathTime(0.0f)
		, mDest(Vector2::Zero)
		,mRadian(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{
	}
	void CatScript::Update()
	{
		mDeathTime += Time::DeltaTime();

		if (mDeathTime > 6.0f)
		{
			//object::Destroy(GetOwner());
		}
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();
		switch (mState)
		{
		case JH::CatScript::eState::SitDown:
			sitDown();
			break;
		case JH::CatScript::eState::Walk:
			move();
			break;
		case JH::CatScript::eState::Sleep:
			break;
		case JH::CatScript::eState::LayDown:
			break;
		case JH::CatScript::eState::Attack:
			break;
		default:
			break;
		}

	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::sitDown()
	{
		mTime += Time::DeltaTime();

		//if (mTime > 2.0f)
			//object::Destroy(GetOwner());

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();


		// 마우스를 통한 이동
		//Transform* plTr = mPlayer->GetComponent<Transform>();
		//Vector2 dest = mDest - plTr->GetPosition();
		//pos += dest.normalize() * (100.0f * Time::DeltaTime());

		//tr->SetPosition(pos);

		//삼각함수를 통한 이동

		//mRadian += 10.f *Time::DeltaTime();
		//
		//pos += Vector2(1.0f, 5*cosf(mRadian) ) * (100.0f * Time::DeltaTime());


		//마우스 위치 방향으로 회전 후 마우스 위치 이동
		//Transform* plTr = mPlayer->GetComponent<Transform>();
		//Vector2 dest = mDest - plTr->GetPosition();

		//dest.normalize();

		//float rotDegree = Vector2::Dot(dest, Vector2::Right);	//cos세타
		////acosf는 라디안 값으로 변환해줌
		//rotDegree = acosf(rotDegree);

		//rotDegree= ConvertDegree(rotDegree);

		//pos += dest.normalize() * (100.0f * Time::DeltaTime());

		//tr->SetPosition(pos);

	//	if (mTime > 3.0f)
	//	{
	//		mState = CatScript::eState::Walk;
	//		int direction = (rand() % 4);
	//		mDirection = (eDirection)direction;
	//		PlayWalkAnimationBydirection(mDirection);
	//		mTime = 0.0f;
	//	}
	}
	void CatScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();

		translate(tr);
		mTime += Time::DeltaTime();

		if (mTime>2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
			mTime = 0.f;
		}
	}
	void CatScript::layDown()
	{

	}
	void CatScript::PlayWalkAnimationBydirection(eDirection dir)
	{
		switch (dir)
		{
		case JH::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);

			break;
		case JH::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);

			break;
		case JH::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);

			break;
		case JH::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);

			break;
		default:
			assert(false);
			break;
		}
	}
	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case JH::CatScript::eDirection::Left:

			pos.x -= 100.0f * Time::DeltaTime();

			break;
		case JH::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case JH::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();

			break;
		case JH::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();

			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}