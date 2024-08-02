#include "JHInput.h"
#include "JHApplication.h"

extern JH::JHApplication application;

namespace JH {

	//static 변수 초기화
	std::vector<Input::Key> Input::Keys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
				'Q','W','E','R','T','Y','U','I','O','P',
				'A','S','D','F','G','H','J','K','L',
				'Z','X','C','V','B','N','M',
				VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,
				MK_LBUTTON,MK_MBUTTON,MK_RBUTTON,
	};


	void Input::Initialize()
	{
		createKeys();

	}

	void Input::createKeys() {
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::updateKeys() {
		std::for_each(Keys.begin(),Keys.end(),
			[](Key& key) -> void {
				updateKey(key);
			}
		);
	}
	void Input::updateKey(Key& key)
	{
		//내 해당 윈도우가 활성화 되어있을 때만
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode)) 
				updateKeyDown(key);
			else
				updateKeyUp(key);
			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Pressed;
		}
		else
		{
			key.state = eKeyState::Down;
		}
		key.bPressed = true;
	}

	void Input::updateKeyUp(Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;

		else
			key.state = eKeyState::None;
		key.bPressed = false;
	}

	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		//전체 윈도우의 좌표
		GetCursorPos(&mousePos);

		ScreenToClient(application.GetHwnd(), &mousePos);

		mMousePosition.x = mousePos.x;
		mMousePosition.y = mousePos.y;
	}

	void Input::clearKeys()
	{
		//창을 내려버리면 key 리셋
		for (Key& key : Keys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed) {
				key.state = eKeyState::Up;
			}
			else if (key.state == eKeyState::Up) {
				key.state = eKeyState::None;
			}

			key.bPressed = false;
		}
	}
	
}
