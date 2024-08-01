#pragma once
#include "../JHSEngine_Source/JHResources.h"
#include "../JHSEngine_Source/JHTexture.h"


namespace JH {
	void LoadResources()
	{

		Resources::Load<graphics::Texture>(L"Chicken", L"..\\Resources\\chicken.bmp");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");

	}
}