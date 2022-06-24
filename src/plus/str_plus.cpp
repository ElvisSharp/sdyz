/*********************************************************
*"str_plus"是对std::string的函数补充
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/
#include <string>
#include <sdyz/plus/str_plus.hpp>

namespace sdyz
{
	//1.去掉字符串两端的字符c
	std::string strip(const std::string& _S, char _Side)
	{
		size_t _S_length = _S.length();
		char* _S_copy = new char[_S_length + 1];
		_S.copy(_S_copy, _S_length);
		_S_copy[_S_length] = '\0';
		int start = 0, end = (int)(_S_length - 1);
		//空串则返回
		if (_S_length == 0)
		{
			return _S;
		}
		//从后往前找
		for (;
			_S_copy[end] == _Side && end >= 0;
			end--);
		if (end < 0)
		{
			return "";
		}
		//从前往后找
		for (start = 0;
			_S_copy[start] == _Side && start <= (int)(_S_length - 1);
			start++);
		_S_copy[end + 1] = '\0';
		std::string temp_result(_S_copy + start);
		delete[] _S_copy;
		return temp_result;
	}

	//2.判断字符串是否由prefix开头
	bool is_start_with(const std::string& _S, const std::string& _Prefix)
	{
		size_t prefix_length = _Prefix.length();
		//取前缀的长度
		std::string _S_prefix = _S.substr(0, prefix_length);
		return _Prefix == _S_prefix ? true : false;
	}

	//3.判断字符串是否由suffix结尾
	bool is_end_with(const std::string& _S, const std::string& _Suffix)
	{
		size_t suffix_length = _Suffix.length();
		//取后缀的长度
		std::string _S_suffix =
			_S.substr(_S.length() - suffix_length, suffix_length);
		return _Suffix == _S_suffix ? true : false;
	}
};
