#pragma once
#include "JHComponent.h"
namespace JH {
	class Collider : public Component
	{
	public:

		Collider(enums::eColliderType type);
		~Collider();


		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		
		virtual void OnColliderEnter(Collider* other);
		virtual void OnColliderStay(Collider* other);
		virtual void OnColliderExit(Collider* other);

		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
		UINT32 GetId() { return mId; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }
		enums::eColliderType GetColliderType() { return mType; }

	private:
		static UINT32 mCollisionID;
		UINT32 mId;
		Vector2 mOffset;
		Vector2 mSize;

		enums::eColliderType mType;
	};
}

