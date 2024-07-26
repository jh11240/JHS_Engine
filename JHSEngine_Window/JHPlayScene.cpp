#include "JHPlayScene.h"
namespace JH {
	JH::PlayScene::PlayScene()
	{
	}

	JH::PlayScene::~PlayScene()
	{
	}

	void JH::PlayScene::Initialize()
	{

		for (size_t i = 0; i < 100; i++) {
			GameObject* objc = new GameObject();
			objc->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(objc);
		}
	}

	void JH::PlayScene::Update()
	{
		Scene::Update();

	}

	void JH::PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

	}

	void JH::PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}
}