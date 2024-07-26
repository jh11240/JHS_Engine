#include "JHGameObject.h"
#include "JHInput.h"
namespace JH {
	GameObject::GameObject() :
		mComponents{}
	{
	}

	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{

		//const int speed = 100.0f;
		////함수가 true면 0x8000을반환함
		//if (Input::GetKey(eKeyCode::A)) {
		//	mX -= speed * Time::DeltaTime();
		//}
		//else if (Input::GetKey(eKeyCode::D)) {
		//	mX += speed * Time::DeltaTime();
		//}
		//else if (Input::GetKey(eKeyCode::W)) {
		//	mY -= speed * Time::DeltaTime();
		//}
		//else if (Input::GetKey(eKeyCode::S)) {
		//	mY += speed * Time::DeltaTime();
		//}

		for (Component* comp : mComponents)
			comp->Update();
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
			comp->LateUpdate();
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




		for (Component* comp : mComponents)
			comp->Render(hdc);
	}
}
