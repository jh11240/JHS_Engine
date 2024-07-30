#pragma once
#include "../JHSEngine_Source/JHResources.h"
#include "../JHSEngine_Source/JHTexture.h"


namespace JH {
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"..\\Resources\\img\\pacman\\0.png");
	}
}