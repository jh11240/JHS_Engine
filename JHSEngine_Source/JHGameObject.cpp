#include "JHGameObject.h"
#include "JHInput.h"
namespace JH {
	GameObject::GameObject() 
		:mX(0)
		,mY(0)
	{
	}

	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{

		const int speed = 100.0f;
		//함수가 true면 0x8000을반환함
		if (Input::GetKey(eKeyCode::A)) {
			mX -= speed * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::D)) {
			mX += speed * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::W)) {
			mY -= speed * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::S)) {
			mY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{

		// 사이클
		// 
		// HPEN mypen - 펜 핸들 선언한다.
		// mypen=CreatePen() - GDI 오브젝트 만듬
		// oldpen = SelectObject() - DC에 선택하되 이전 핸들 저장!
		// RECTangle, Ellipse ... 사용한다.
		// SelectObject() 다시 선택을 해제한다.
		// DeleteObject() 삭제한다.


//파랑 브러쉬 생성
		HBRUSH brush = CreateSolidBrush(RGB(rand()%255, rand() % 255, rand() % 255));
		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_DOT, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, mX, mY,100 + mX, 100 + mY);
		SelectObject(hdc, oldBrush);

		DeleteObject(brush);
		DeleteObject(redPen);
	}
}
