#pragma once
#include "JHEntity.h"
namespace JH
{
	class Resource: public Entity
	{


	public:
		Resource(enums::eResourceType type);

		virtual ~Resource();

		//similar to bool / window predefined type
		virtual HRESULT Load(const std::wstring& path) =0;		

		const std::wstring& GetPath(){ return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};


	}
