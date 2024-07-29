#pragma once
#include "../JHSEngine_Source/JHResources.h"
#include "../JHSEngine_Source/JHTexture.h"


namespace JH {
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"D:\\JH\\JHSEngine\\Resources\\PegasusWhited.png");

	}
}