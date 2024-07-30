#pragma once
#include "..\\JHSEngine_Source\\JHScript.h"

namespace JH
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update()   override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:

	};
}
