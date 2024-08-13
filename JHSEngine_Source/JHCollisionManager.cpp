#include "JHCollisionManager.h"
#include "JHScene.h"
#include "JHSceneManager.h"
#include "JHGameObject.h"
#include "JHTransform.h"
#include "JHCollider.h"
namespace JH
{
	std::bitset<(UINT)enums::eLayerType::Max>CollisionManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{

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
				if (right->IsActive() == false) {
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
		// 두 충돌체 번호를 가져온 id를 가져와 colllision id 값 세팅
		CollisionID id = {};
		id.left = left->GetId();
		id.right = right->GetId();

		//해당 id로 충돌체 정보를 검색해준다.
		// 만약 충돌체 정보가 없다면 충돌정보를생성
		auto iter = mCollisionMap.find(id.id);

		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		//충돌 체크를 해주면 된다.
		if (Intersect(left, right))
		{
			//이전에 충돌 안했던거면 최초 충돌
			if (iter->second == false)
			{
				left->OnColliderEnter(right);
				right->OnColliderEnter(left);
				iter->second = true;
			}
			else
			{
				left->OnColliderStay(right);
				right->OnColliderStay(left);
			}
		}
		else
		{
			if (iter->second == true)
			{
				left->OnColliderExit(right);
				right->OnColliderExit(left);
				iter->second = false;
			}
		}


	}
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();


		//size 1,1일 기본크기 100픽셀
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		//AABB충돌
		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Rect2D)
		{
			//rect
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}

		}
		if (leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Circle2D)
		{
			//circle 

			Vector2 leftCirclePos = leftPos + leftSize / 2.0f;
			Vector2 rightCirclePos = rightPos + rightSize / 2.0f;

			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= leftSize.x / 2.0f + rightSize.x / 2.0f)
			{
				return true;
			}
		}

		if (leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
		{
			if(((leftPos.x > (rightPos.x - rightSize.x /2.0f-leftSize.x ) )&& (leftPos.x < (rightPos.x + rightSize.x /2.0f+leftSize.x ))) 
				&& ((leftPos.y > (rightPos.y - rightSize.y / 2.0f - leftSize.y)) && (leftPos.y < (rightPos.y + rightSize.y / 2.0f + leftSize.y))))

				return true;
		}
		if (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D)
		{

			}


		return false;
	}
}