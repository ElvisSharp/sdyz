#include <sdyz/plus/rand_plus.hpp>

namespace sdyz
{
    using std::string;

	//随机返回0或1
	int rand01()
	{
		srand((unsigned)time(NULL));
		int res = rand() % 2;
		return res;
	}

	//TODO: 返回一个begin~end之间的随机整数，[begin, end)
	int randint(int _Begin, int _End)
	{
		return 0;
	}

	//TODO: 返回0~end之间一个随机整数，[0, end)
	int randint(int _End)
	{
		return 0;
	}

	// 随机密码
	std::string rndpwd()
	{
        // 随机生成的密码基于两个字符串
        const char* charArr1 =
            "2hq18e65c4f2s38l3r72j4dw19zv869tn1u6ix9yp7obag455m7k3";
        const char* charArr2 =
            "91FQ38K3U979VC854TZO46NJE1H2XGSIB53LWYM64PDAR61757228";
        string s1(charArr1);
        string s2(charArr2);
        string allS = s1 + s2;
        int N = allS.size();
        auto RandDYZ = [=]() -> std::string {
            std::string dyz("dyz");
            for (int i = 0; i < dyz.length(); i++)
                dyz[i] -= (32 * (rand() % 2));
            return dyz;
        };
        // 添加12个随机数字或字母
        string s("");
        srand((int)time(NULL));
        s += RandDYZ();
        for (int i = 0; i < 12; i++) {
            int r = rand() % N;
            s += allS[r];
        }
        return s;
	}
}