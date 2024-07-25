#pragma once
#include "JHGameObject.h"

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

		//플레이어

		GameObject mPlayer;
	};


}

