#pragma once
#include "JHCollider.h"
namespace JH {

class BoxCollider2D : public Collider
{
public:

	BoxCollider2D();
	~BoxCollider2D();


	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

private:
	Vector2 size;
};

}
