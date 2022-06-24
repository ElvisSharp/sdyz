/*********************************************************
*"cast"实现了一些类型间的转换
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#pragma once
#include <string>
#include <sstream>

namespace sdyz
{


	template<typename SRC_TYPE,
		typename DES_TYPE>
		DES_TYPE cast(const SRC_TYPE& _Obj)
	{
		DES_TYPE obj;
		return obj;
	}

	template<>
	inline int cast<std::string, int>(const std::string& _Str)
	{
		int res = atoi(_Str.c_str());
		return res;
	}

}
