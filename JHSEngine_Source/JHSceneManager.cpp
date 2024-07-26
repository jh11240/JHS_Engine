#include "JHSceneManager.h"
namespace JH {
	std::map<const std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = {};

	void SceneManager::Initialize()
	{
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();

	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);

	}

}