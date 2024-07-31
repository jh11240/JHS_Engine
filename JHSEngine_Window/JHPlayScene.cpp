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
#include "JHPlayerScript.h"
#include "JHCamera.h"
#include "JHRenderer.h"
#include "JHAnimator.h"

namespace JH {
	PlayScene::PlayScene()
		:mPlayer(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{

		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.f,442.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//우린 sprite renderer에서 camera가 바라보는 좌표를 중심으로 좌표를 다시 계산하게 된다. 
		// 여기서 카메라를 움직여버리면 메인카메라가 움직이므로 
		// 매프레임 작동하는 render함수에서 기존에 있던 스프라이트들의 transform도 메인카메라를 기준으로 다시 계산하므로 
		// 기존에 멈춘 스프라이트들이 카메라와 거꾸로 움직이는것처럼 보인다. 
		//  하지만 스프라이트들이 실제로 카메라의 반대로 이동하진 않으므로 카메라 이동한만큼 반대로 더 이동해서 두배씩 이동하는 일은 생기지 않는다
		//camera->AddComponent<PlayerScript>();

		mPlayer = object::Instantiate<Player>
			(enums::eLayerType::Particle);
		/*SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.f, 3.f));*/
		mPlayer->AddComponent<PlayerScript>();

		//graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"MapleEffect");
		//Animator* animator= mPlayer->AddComponent<Animator>();
		//animator->CreateAnimation(L"CatFrontMove", packmanTexture, 
		//	Vector2(0.f , 0.f), Vector2(386.0f, 246.f), Vector2::Zero, 8, 0.1f);

		//animator->PlayAnimation(L"CatFrontMove", true);
		
		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator= mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", packmanTexture, 
			Vector2(0.f , 0.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);


		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.f, 100.f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.f, 2.f));
		animator->PlayAnimation(L"CatFrontMove", true);
		//mPlayer->GetComponent<Transform>()->SetRotation(30.f);
		//sr->SetTexture(packmanTexture);

		GameObject* bg= object::Instantiate<GameObject>
			(enums::eLayerType::Player);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		//bgSr->SetSize(Vector2(3.f, 3.f));
		//bg->AddComponent<PlayerScript>();

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Bubble");
		bgSr->SetTexture(bgTexture);

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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 11);
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