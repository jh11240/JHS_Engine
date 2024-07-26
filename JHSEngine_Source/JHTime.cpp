#include "JHTime.h"

namespace JH {

	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.f;

	void Time::Initialize()
	{
		//cpu 고유 진동수 (1초당 틱수)
		QueryPerformanceFrequency(&CpuFrequency);

		//현재 틱수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{

		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency
			=static_cast<float>( CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC dc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		wchar_t str[50] = L"";
		float fps = 1.0f / DeltaTimeValue;
		swprintf_s(str, 50, L"FPS : %d", (int)fps);
		int len = wcsnlen_s(str, 50);


		TextOut(dc, 0, 0, str, len);
	}
}
