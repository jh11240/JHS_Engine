#include "JHApplication.h"
#include "JHInput.h"
#include "JHTime.h"
#include "JHSceneManager.h"
#include "JHResources.h"
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

		Destroy();
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

	void JHApplication::Destroy()
	{
		SceneManager::Destroy();

	}

	void JHApplication::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}

	void JHApplication::clearRenderTarget()
	{		
		//clear Clearing
		Rectangle(mBackHDC, -1, -1, 1601, 901);
	}
	void JHApplication::copyRenderTarget(HDC source, HDC dest)
	{

		///back buffer 
		BitBlt(dest, 0, 0, mWidth, mHeight
			, source, 0, 0, SRCCOPY);
	}
	void JHApplication::adjustWindowRect(HWND hwnd, UINT width, UINT height) {

		RECT rect = { 0,0,width ,height };

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;


		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);

		ShowWindow(hwnd, true);
	}
	void JHApplication::createBuffer(UINT width, UINT height) {

		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);


		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void JHApplication::initializeEtc() {
		Input::Initialize();
		Time::Initialize();
	}
}