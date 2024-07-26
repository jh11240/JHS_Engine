#pragma once
#include "JHComponent.h"
#include "CommonInclude.h"
#include "JHTransform.h"

namespace JH {
	class SpriteRenderer:public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc) override;
	};
}

