/*********************************************************
*"file_plus"是对文件操作的函数补充
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/
#pragma once

#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>

#include <sdyz/vector/byte_vector.hpp>

namespace sdyz
{
	typedef std::string string;
	//计算文件大小
	size_t get_size(const string& _Path);
};





