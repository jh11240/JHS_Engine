#pragma once
#include "JHScene.h"

namespace JH {
	//이 scenemanager도 여러씬에서 호출될수 있으므로 static으로 변수, 함수 구현
	class SceneManager
	{
	public:
		template <typename T>
		static  Scene* CreateScene(const std::wstring& name)
		{
			T* Scene = new T();
			Scene->SetName(name);
			mActiveScene = Scene;
			Scene->Initialize();

			mScene.insert(std::make_pair(name, Scene));

			

			return Scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			if (mActiveScene)
				mActiveScene->OnExit();


			std::map<std::wstring,Scene*>::iterator iter = mScene.find(name);

			if (iter == mScene.end())
			{
				return nullptr;
			}
			mActiveScene = iter->second;
			mActiveScene->OnEnter();

			return iter->second;
		}

		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Release();

		//static SceneManager& GetInst()
		//{
		//	static SceneManager sceneManager;
		//	return sceneManager;
		//}
	//private:
	//	SceneManager();
	//	~SceneManager();

	private:
		//static std::vector<Scene*> mScene;
		static std::map<const std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};

	//static SceneManager sceneManager;
}
