#pragma once
#include "JHGameObject.h"
#include "JHTime.h"

namespace JH {

	class JHApplication
	{
	public:
		JHApplication();
		~JHApplication();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
		void Release();

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();
		HWND mHwnd;
		HDC mHdc;


		HDC mBackHDC;
		//압축이 안된 원본 그림파일
		HBITMAP mBackBitmap;


		UINT mWidth;
		UINT mHeight;

		//플레이어

		//std::vector<GameObject*> mGameObjects;
	};


}

