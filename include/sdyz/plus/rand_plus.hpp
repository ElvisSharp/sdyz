/*********************************************************
*"rand_plus"包含了一些随机函数
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/
#pragma once
#include <cstdlib>
#include <ctime>


namespace sdyz
{
	//随机返回0或1
	int rand01();

	//返回一个begin~end之间的随机整数，[begin, end)
	int randint(int _Begin, int _End);
	
	//返回0~end之间一个随机整数，[0, end)
	int randint(int _End);
}