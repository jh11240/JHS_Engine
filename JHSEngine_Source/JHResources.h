#pragma once
#include "JHResource.h"

namespace JH {
	class Resources 
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& key)
		{
			//std::map<std::wstring, Resource*>::iterator iter = mResources.find(key);
			auto iter = mResources.find(key);

			if (iter == mResources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);

			if (resource != nullptr)
				return resource;

			resource = new T();
			if ( FAILED(resource->Load(path)) )
			{
				assert(false);
			}
			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

		static void Insert(const std::wstring& key,  Resource* resource)
		{
			if (key == L"")
				return;

			if (resource == nullptr)
				return;

			mResources.insert(std::make_pair(key, resource));

		}

		static void Release()
		{
			for (auto& iter : mResources)
			{
				delete iter.second;
				iter.second = nullptr;
			}
		}
	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}
//게임에서 사용되는 데이터 종류

// 이미지, 사운드,, 3스테이지 클리어

//저장 게임 플레이데이터 HDD, 클라우드 저장을 해둔다.
//이것도 리소스