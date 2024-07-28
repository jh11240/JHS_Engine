#pragma once
#include "../JHSEngine_Source/JHSceneManager.h"
#include "JHPlayScene.h"
#include "JHTitleScene.h"

namespace JH {
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"TitleScene");
		
	}
}