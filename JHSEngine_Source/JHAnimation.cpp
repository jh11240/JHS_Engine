#include "JHAnimation.h"
#include "JHTime.h"
#include "JHTransform.h"
#include "JHGameObject.h"
#include "JHAnimator.h"
#include "JHRenderer.h"
#include "JHCamera.h"
namespace JH
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		,mIndex(-1)
		,mTime(0.0f)
		,mbComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		SetName(name);
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + size.x * i;
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		mTime = 0.f;
		mIndex = 0;
		mbComplete = false;

	}
	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			if (mIndex< mAnimationSheet.size()-1)
			{
				mIndex++;
			}
			else
			{
				mbComplete = true;
			}
			//초기화 중요
			mTime = 0;
		}
	}
	void Animation::Render(HDC hdc)
	{
		//알파 블렌드를 쓸 수 있는 조건: 해당 이미지 알파채널이 있어야 한다.
		//AlphaBlend(125, );

		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();

		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
		{
			pos= renderer::mainCamera->CalculatePosition(pos);
		}

		graphics::Texture::eTextureType type= mTexture->GetTextureType();
		Sprite sprite = mAnimationSheet[mIndex];
		if (type == graphics::Texture::eTextureType::Bmp)
		{
			//BLENDFUNCTION func = {};
			//func.BlendOp = AC_SRC_OVER;
			//func.BlendFlags = 0;
			//func.AlphaFormat = AC_SRC_ALPHA;
			//func.SourceConstantAlpha = 255;		// 0(transparent) ~ 255 (Opaque)

			HDC imgHdc = mTexture->GetHdc();

			//AlphaBlend
			// (hdc, 
			//	//offset 해당 스프라이트의 중심으로 맞추기 lefttop말고
			//	pos.x - (sprite.size.x /2.f), pos.y - (sprite.size.y / 2.f),
			//	sprite.size.x * scale.x,
			//	sprite.size.y * scale.y,
			//	imgHdc,
			//	sprite.leftTop.x,
			//	sprite.leftTop.y,
			//	sprite.size.x,
			//	sprite.size.y,
			//	func);

			TransparentBlt(
				hdc, 
				//offset 해당 스프라이트의 중심으로 맞추기 lefttop말고
				pos.x - (sprite.size.x /2.f), pos.y - (sprite.size.y / 2.f),
				sprite.size.x * scale.x,
				sprite.size.y * scale.y,
				imgHdc,
				sprite.leftTop.x,
				sprite.leftTop.y,
				sprite.size.x,
				sprite.size.y
				,RGB(255, 0, 255));
		}
		else if (type == graphics::Texture::eTextureType::Png)
		{
			//내가 원하는 픽셀을 투명화 시킬 때
			Gdiplus::ImageAttributes imgAtt = {};

			//투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(230,230,230),Gdiplus::Color(255,255,255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(
				mTexture->GetImage(),
				Gdiplus::Rect
				{
					(INT)(pos.x - (sprite.size.x / 2.f)), (INT)(pos.y- (sprite.size.y / 2.f))
					, (INT)(sprite.size.x * scale.x)
					,(INT)(sprite.size.y* scale.y)
				}
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				,&imgAtt
			);
		}


	}
}