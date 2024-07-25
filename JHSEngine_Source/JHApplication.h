#pragma once
#include "CommonInclude.h"

namespace JH {

	class JHApplication
	{
	public:
		JHApplication();
		~JHApplication();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;
		float mX;
		float mY;
	};


}

