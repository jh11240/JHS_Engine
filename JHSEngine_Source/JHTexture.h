#pragma once
#include "JHResource.h"

namespace JH::graphics
{


	class Texture : public Resource
	{
	public:
		enum class eTextureType 
		{
			Bmp,
			Png,
			None,
		};
		

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		eTextureType mType;
		//GDI +
		Gdiplus::Image* mImage;
		//just GDI
		HBITMAP mBitmap;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}
