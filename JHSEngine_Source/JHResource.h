#pragma once
#include "JHEntity.h"
namespace JH
{
	class Resource: public Entity // 추상 클래스 메모리 할당 x 상속받아서만 사용해야한다.
	{

	public:
		Resource(enums::eResourceType type);

		virtual ~Resource();

		//similar to bool / window predefined type
		virtual HRESULT Load(const std::wstring& path) =0;		// 순수 가상함수 실제 메모리에 할당 불가능 무조건 상속받아서 써라

		const std::wstring& GetPath(){ return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};


	}
