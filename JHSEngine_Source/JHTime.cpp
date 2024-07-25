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
}
