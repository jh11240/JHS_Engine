#include "JHPlayScene.h"
#include "JHGameObject.h"
#include "JHPlayer.h"
#include "JHTransform.h"
#include "JHSpriteRenderer.h"
#include "JHInput.h"
#include "JHTitleScene.h"
#include "JHSceneManager.h"
#include "JHObject.h"
#include "JHTexture.h"
#include "JHResources.h"

namespace JH {
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{

		// 
			//bg = new Player();
			//Transform* tr = bg->AddComponent<Transform>();

			//tr->SetPosition(Vector2(0,0));

			//tr->SetName(L"TR");

			//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

			//sr->SetName(L"SR");

			//AddGameObject(bg, enums::eLayerType::BackGround);
			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround, Vector2(100.0f,100.0f));
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
			sr->SetTexture(bg);
			

			//graphics::Texture* tex = new  graphics::Texture();
			//tex->Load(L"D:\\JH\\JHSEngine\\Resources\\PegasusWhited.png");
			

			//sprite renderer���� texture�� �ű�� ���� tex�� �ٽ� �ű�
			//sr->ImageLoad(L"D:\\JH\\JHSEngine\\Resources\\PegasusWhited.png");
			//절대 경로
			//상대 경로

			Scene::Initialize();
		
	}

	void PlayScene::Update()
	{
		Scene::Update();

	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}

	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 11);

	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();

		//tr->SetPosition(Vector2(0, 0));
	}
}