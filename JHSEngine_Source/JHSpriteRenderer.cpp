#include "JHSpriteRenderer.h" 
#include "JHGameObject.h"
#include "JHTexture.h"
namespace JH {
	SpriteRenderer::SpriteRenderer()
		:Component()
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

		if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Bmp)
		{
			//transparentBlt는 
			TransparentBlt(hdc,pos.x,pos.y
				,mTexture->GetWidth() * mSize.x,mTexture->GetHeight() * mSize.y, mTexture->GetHdc()
				,0,0,mTexture->GetWidth(), mTexture->GetHeight(),
				RGB(255,0,255 ));
		}
		else if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth()*mSize.x, mTexture->GetHeight() *mSize.y));
		}
		//Gdiplus::Graphics graphics(hdc);
		//graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));

	}

}