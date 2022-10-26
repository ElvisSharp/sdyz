/*********************************************************
*"sha1"包含了sha1算法的函数
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#pragma once
#include<string>

#include<sdyz/algorithm/hash/sha1_core.hpp>
#include<sdyz/vector/byte_vector.hpp>

namespace sdyz
{
	typedef std::string string;

	template <typename T>
	inline byte_vector sha1(const T& _T)
	{
		T t = _T;
		byte_vector res_vec(20, 0);
		sha1_core::SHA1((const byte*)&t, sizeof(t), res_vec.data());
		return res_vec;
	}

	template <>
	inline byte_vector sha1<string>(const string& _Str)
	{
		byte_vector str_vec = to_byte_vector(_Str);
		byte_vector res_vec(20, 0);
		sha1_core::SHA1(str_vec.data(), str_vec.size(), res_vec.data());
		return res_vec;
	}

	template <>
	inline byte_vector sha1<byte_vector>(const byte_vector& _Byte_Vec)
	{
		byte_vector res_vec(20, 0);
		sha1_core::SHA1(_Byte_Vec.data(), _Byte_Vec.size(), res_vec.data());
		return res_vec;
	}

}