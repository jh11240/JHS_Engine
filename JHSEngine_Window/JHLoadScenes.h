#pragma once
#include "../JHSEngine_Source/JHSceneManager.h"
#include "JHPlayScene.h"

namespace JH {
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
		
	}
}