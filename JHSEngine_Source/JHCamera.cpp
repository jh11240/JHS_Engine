#include "JHCamera.h"
#include "JHGameObject.h"
#include "JHTransform.h"
#include  "JHApplication.h"

extern JH::JHApplication application;
namespace JH
{
	Camera::Camera()
		: Component(enums::eComponenetType::Camera)
		,mDistance(Vector2::Zero)
		,mResolution(Vector2(1600.0f, 900.0f))
		,mLookPosition(Vector2::Zero)
		,mTarget(nullptr)
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}

	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameraTr->GetPosition();

		//늘 화면 중심 기준으로 보게되므로 원점이 (0,0)지점이 아니라 카메라 위치 + (해상도의 절반 ,해상도의 절반) 이다. 따라서 떨어진 거리는 현재 보고 있는 지점에서 해상도 /2 만큼씩 빼줘야한다.
		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::LateUpdate()
	{

	}
	void Camera::Render(HDC hdc)
	{

	}

}

