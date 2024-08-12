#pragma once
#include "CommonInclude.h"
#include "JHBoxCollider2D.h"
#include "JHCircleCollider2D.h"
namespace JH {

	using namespace enums;


	class CollisionManager
	{

	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);

		static void ColliderCollision(Collider* left, Collider* right);


	private:
		static std::bitset<(UINT)enums::eLayerType::Max>mCollisionLayerMatrix[(UINT)enums::eLayerType::Max];
	};
}

