#include "JHInput.h"
#include"algorithm"
namespace JH {

	//static 변수 초기화
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
				'Q','W','E','R','T','Y','U','I','O','P',
				'A','S','D','F','G','H','J','K','L',
				'Z','X','C','V','B','N','M',
				VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,
				MK_LBUTTON,MK_RBUTTON,
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
		if (isKeyDown(key.keyCode)) {
			updateKeyDown(key);
		}
		else 
			updateKeyUp(key);
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Key& key)
	{
		if (Keys[i].bPressed == true)
		{
			Keys[i].state = eKeyState::Pressed;
		}
		else
		{
			Keys[i].state = eKeyState::Down;
		}
		Keys[i].bPressed = true;
	}

	void Input::updateKeyUp(Key& key)
	{
		if (Keys[i].bPressed == true)
			Keys[i].state = eKeyState::Up;

		else
			Keys[i].state = eKeyState::None;
		Keys[i].bPressed = false;
	}
	
}
