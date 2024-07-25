#include "JHTime.h"

namespace JH {

	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	static float DeltaTime = 0.f;

	void JH::Time::Initialize()
	{
		//cpu 고유 진동수 (1초당 틱수)
		QueryPerformanceFrequency(&CpuFrequency);

		//현재 틱수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void JH::Time::Update()
	{

		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency
			=static_cast<float>( CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC dc)
	{
		static float time = 0.0f;

		time += DeltaTime;
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %f", time);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}
