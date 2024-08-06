#pragma once
#include "JHResource.h"
//texture내부에 resource #include라 상관없지 않나요? -> 이 클래스가 어떤 클래스를 사용하는지 알 수 있음
#include "JHTexture.h"

namespace JH 
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				,size(Vector2::Zero)
				,offset(Vector2::Zero)
				,duration(0.0f)
			{
			}
		};

		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;
		
		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);


		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }

		void Update();
		void Render(HDC hdc);

	private:
		class Animator* mAnimator;
		graphics::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;
	};
}

