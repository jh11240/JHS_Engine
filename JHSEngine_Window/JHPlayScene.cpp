#include "JHPlayScene.h"
#include "JHGameObject.h"
#include "JHPlayer.h"
#include "JHTransform.h"
#include "JHSpriteRenderer.h"

namespace JH {
	JH::PlayScene::PlayScene()
	{
	}

	JH::PlayScene::~PlayScene()
	{
	}

	void JH::PlayScene::Initialize()
	{
		{
			Player* bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();

			tr->SetPos(Vector2(0,0));

			tr->SetName(L"TR");

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

			sr->SetName(L"SR");
			sr->ImageLoad(L"D:\\Source\\Resources\\PegasusWhited.png");

			AddGameObject(bg);
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