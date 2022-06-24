#include <sdyz/plus/rand_plus.hpp>

namespace sdyz
{

	//随机返回0或1
	int rand01()
	{
		srand((unsigned)time(NULL));
		int res = rand() % 2;
		return res;
	}

	//返回一个begin~end之间的随机整数，[begin, end)
	int randint(int _Begin, int _End)
	{
		return 0;
	}

	//返回0~end之间一个随机整数，[0, end)
	int randint(int _End)
	{
		return 0;
	}
}