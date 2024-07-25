#pragma once
#include "CommonInclude.h"
namespace JH 
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();



	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTime;
	};

}
