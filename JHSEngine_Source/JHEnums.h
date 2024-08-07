#pragma once


namespace JH::enums
{
	enum class eComponenetType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End,
	};
	enum class eLayerType
	{
		None,
		BackGround,
		//Tree
		//character
		Animal,
		Player,
		Particle,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
}