#include "JHApplication.h"
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
	}
	void JHApplication::Update() {
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
        mPlayer.Render(mHdc);
	}
}