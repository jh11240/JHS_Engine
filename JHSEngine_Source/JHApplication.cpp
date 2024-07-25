#include "JHApplication.h"
#include "JHInput.h"
#include "JHTime.h"
namespace JH
{
    JHApplication::JHApplication()
        :mHwnd(nullptr), mHdc(nullptr)
    {

    }
    JHApplication::~JHApplication() {


    }

	void JHApplication::Initialize(HWND hwnd) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

        mPlayer.SetPosition(0.f, 0.f);
		Input::Initialize();
	}
	void JHApplication::Update() {

		Input::Update();

        mPlayer.Update();
	}
	void JHApplication::Run() {
		Update();
		LateUpdate();
		Render();
	}
	void JHApplication::LateUpdate() {

	}
	void JHApplication::Render() 
    {
		Time::Render(mHdc);
        mPlayer.Render(mHdc);
	}
}