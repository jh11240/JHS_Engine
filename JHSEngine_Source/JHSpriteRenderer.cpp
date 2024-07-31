#include "JHSpriteRenderer.h" 
#include "JHGameObject.h"
#include "JHTexture.h"
#include "JHRenderer.h"
namespace JH {
	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponenetType::SpriteRenderer)
		,mTexture(nullptr)
		,mSize(Vector2(1.0f,1.0f))
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{

	}

	void SpriteRenderer::Render(HDC hdc)
	{

		if (mTexture == nullptr)	//텍스쳐 세팅 해주세요!
		{
			assert(false);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();

		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Bmp)
		{
			//transparentBlt는 
			TransparentBlt(hdc,pos.x,pos.y
				,mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y, mTexture->GetHdc()
				,0,0,mTexture->GetWidth(), mTexture->GetHeight(),
				RGB(255,0,255 ));
		}
		else if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Png)
		{
			//내가 원하는 픽셀을 투명화 시킬 때
			Gdiplus::ImageAttributes imgAtt = {};

			//투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(200, 200, 200), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x, pos.y
					,mTexture->GetWidth()*mSize.x*scale.x
					, mTexture->GetHeight() *mSize.y*scale.y
				)
				,0,0
				, mTexture->GetWidth() ,  mTexture->GetHeight()
				,Gdiplus::UnitPixel
				,nullptr /*&imgAtt*/
			);


		}

	}

}