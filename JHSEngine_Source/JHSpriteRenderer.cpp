#include "JHSpriteRenderer.h"

namespace JH {
	SpriteRenderer::SpriteRenderer()
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
		//파랑 브러쉬 생성
		HBRUSH brush = CreateSolidBrush(RGB(rand()%255, rand() % 255, rand() % 255));
		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_DOT, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		Ellipse(hdc, mX, mY,100 + mX, 100 + mY);
		SelectObject(hdc, oldBrush);

		DeleteObject(brush);
		DeleteObject(redPen);
	}
}