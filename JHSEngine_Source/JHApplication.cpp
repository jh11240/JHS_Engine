#include "JHApplication.h"
#include "JHInput.h"
#include "JHTime.h"
namespace JH
{
	JHApplication::JHApplication()
		:mHwnd(nullptr), mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHDC(NULL)
		, mBackBitmap(NULL)
    {

    }
    JHApplication::~JHApplication() {


    }

	void JHApplication::Initialize(HWND hwnd,UINT width, UINT height) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = {0,0,width ,height};
		//실제 작업 영역 구하고
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		//window position 다시 지정
		SetWindowPos(mHwnd,nullptr,0,0, mWidth,mHeight,0);
		//다시 화면 띄워줌
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width,height);

		//백버퍼를 가르킬 DC생성
		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHDC,mBackBitmap);
		DeleteObject(oldBitmap);

        mPlayer.SetPosition(0.f, 0.f);
		Input::Initialize();
		Time::Initialize();
	}
	void JHApplication::Update() {

		Input::Update();
		Time::Update();
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
		Rectangle(mBackHDC, 0, 0, 1600, 900);

		Time::Render(mBackHDC);
        mPlayer.Render(mBackHDC);

		///back buffer에 있는걸 원본 buffer에 복사함
		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHDC, 0, 0, SRCCOPY);
	}
}