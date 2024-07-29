#include "JHPlayer.h"
#include "JHInput.h"
#include "JHTime.h"
#include "JHTransform.h"

namespace JH {
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr= GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
				
		}
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}