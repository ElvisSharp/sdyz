/*********************************************************
*"file_plus"是对文件操作的函数补充
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <sdyz/vector/byte_vector.hpp>
#include <sdyz/plus/file_plus.hpp>

namespace sdyz
{
	size_t get_size(const string& _Path)
	{
		std::fstream fs(_Path.c_str(), std::ios::binary | std::ios::in);
		fs.seekg(0, std::ios::end);
		size_t file_size = fs.tellg();
		fs.close();
		return file_size;
	}
}