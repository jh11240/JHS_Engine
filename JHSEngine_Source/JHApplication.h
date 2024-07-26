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


	private:
		HWND mHwnd;
		HDC mHdc;


		HDC mBackHDC;
		//압축이 안된 원본 그림파일
		HBITMAP mBackBitmap;


		UINT mWidth;
		UINT mHeight;

		//플레이어
		GameObject mPlayer;
	};


}

