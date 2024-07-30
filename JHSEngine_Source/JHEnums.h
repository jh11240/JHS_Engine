#pragma once


namespace JH::enums
{
	enum class eComponenetType
	{
		Transform,
		SpriteRenderer,
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
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}