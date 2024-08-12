#include "JHCollisionManager.h"
#include "JHScene.h"
#include "JHSceneManager.h"
#include "JHGameObject.h"
#include "JHCollider.h"
namespace JH
{
	std::bitset<(UINT)enums::eLayerType::Max>CollisionManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};


	void CollisionManager::Initialize()
	{
		int a = 1;
		a << 1;

	}
	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene,(eLayerType)row, (eLayerType)col);
				}
			}
		}
	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render(HDC hdc)
	{
	}
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;

		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}
	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* left : lefts) 
		{
			if (left->IsActive() == false) {
				continue;
			}

			Collider* leftCol = left->GetComponent<Collider>();

			if (leftCol == nullptr)
				continue;
			for (GameObject* right : rights)
			{
				if (left->IsActive() == false) {
					continue;
				}
				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol== nullptr)
					continue;
				//두 오브젝트 같으면 패스
				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		//충돌체크 로직
	}
}