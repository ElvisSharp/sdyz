/*********************************************************
*"str_plus"是对std::string的函数补充
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/
#pragma once

#include <string>

namespace sdyz
{
	//1.去掉字符串两端的字符c
	std::string strip(const std::string& _S, char _Side);
	
	//2.判断字符串是否由prefix开头
	bool is_start_with(const std::string& _S, const std::string& _Prefix);

	//3.判断字符串是否由suffix结尾
	bool is_end_with(const std::string& _S, const std::string& _Suffix);
};
