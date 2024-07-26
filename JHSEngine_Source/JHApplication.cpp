#include "JHApplication.h"
#include "JHInput.h"
#include "JHTime.h"
#include "JHSceneManager.h"
namespace JH
{
	JHApplication::JHApplication()
		:mHwnd(nullptr), mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHDC(NULL)
		, mBackBitmap(NULL)
		//,mGameObjects{}
    {

    }
    JHApplication::~JHApplication() {


    }

	void JHApplication::Initialize(HWND hwnd,UINT width, UINT height) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		SceneManager::Initialize();

		adjustWindowRect(mHwnd, width, height);

		createBuffer(width, height);

		initializeEtc();
	}
	void JHApplication::Update() {

		Input::Update();
		Time::Update();

		SceneManager::Update();

	}
	void JHApplication::Run() {
		Update();
		LateUpdate();
		Render();
	}
	void JHApplication::LateUpdate() {
		SceneManager::LateUpdate();
	}
	void JHApplication::Render() 
    {
		clearRenderTarget();

		Time::Render(mBackHDC);


		SceneManager::Render(mBackHDC);

		copyRenderTarget(mBackHDC, mHdc);
	}

	void JHApplication::clearRenderTarget()
	{		
		//clear 이게 하얀 배경 역할을 함
		Rectangle(mBackHDC, -1, -1, 1601, 901);
	}
	void JHApplication::copyRenderTarget(HDC source, HDC dest)
	{

		///back buffer에 있는걸 원본 buffer에 복사함
		BitBlt(dest, 0, 0, mWidth, mHeight
			, source, 0, 0, SRCCOPY);
	}
	void JHApplication::adjustWindowRect(HWND hwnd, UINT width, UINT height) {

		RECT rect = { 0,0,width ,height };
		//실제 작업 영역 구하고
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		//window position 다시 지정
		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		//다시 화면 띄워줌
		ShowWindow(hwnd, true);
	}
	void JHApplication::createBuffer(UINT width, UINT height) {
		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void JHApplication::initializeEtc() {
		Input::Initialize();
		Time::Initialize();
	}
}