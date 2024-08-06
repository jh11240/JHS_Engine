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
#include "JHCat.h"
#include "JHCatScript.h"

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
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();


		
		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator= mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTex, 
			Vector2(2000.f , 250.f), Vector2(250.f, 250.f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex, 
			Vector2(0.f , 2000.f), Vector2(250.f, 250.f), Vector2::Zero, 12, 0.1f);



		playerAnimator->PlayAnimation(L"Idle", false);
		playerAnimator->GetCompleteEvent(L"FrontGiveWater" ) = std::bind(&PlayerScript::AttackEffect,plScript );

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.f, 100.f));
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.f, 2.f));


		/// CAT

		Cat* cat = object::Instantiate<Cat>
			(enums::eLayerType::Animal);
		//cat->SetActive(true);
		cat->AddComponent<CatScript>();


		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
	/*	catAnimator->CreateAnimation(L"DownWalk", catTex,
			Vector2(0.f, 0.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex,
			Vector2(0.f, 32.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex,
			Vector2(0.f, 64.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex,
			Vector2(0.f, 96.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex,
			Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex,
			Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTex,
			Vector2(0.f, 192), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.1f);


		catAnimator->PlayAnimation(L"SitDown", false);*/

		catAnimator->CreateAnimationByFolder(L"MushroomIdle",L"..\\Resources\\Mushroom", Vector2::Zero,
		 0.1f);
		catAnimator->PlayAnimation(L"MushroomIdle", true);

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.f, 200.f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.f, 2.f));

		//cameraComp->SetTarget(cat);

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