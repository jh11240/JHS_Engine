#pragma once
#include "CommonInclude.h"
namespace JH 
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC dc);
		
		//컴파일러가 무조건 쓰는건 아니지만 좀더 확률 업
		__forceinline static float DeltaTime() { return DeltaTimeValue;}

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};

}
