#pragma once
#include "CommonHeader.h"

namespace dev
{
	class Object
	{
	public:
		Object();
		~Object();

	public:
		void SetName(const wchar_t* name)
		{
			wcscpy_s(_name, name);
		}

		wchar_t* GetName()
		{
			return _name;
		}

	private:
		wchar_t _name[50];
	};
}