#pragma once
#include <bitset>

namespace sdyz 
{
	namespace aes_core
	{
		typedef std::bitset<8> std_byte;
		typedef std::bitset<32> std_word;
		using namespace std;
		extern const int Nr;  // AES-128需要 10 轮加密
		extern const int Nk;   // Nk 表示输入密钥的 word 个数
		//密钥扩展
		void KeyExpansion(std_byte* key, std_word* w);
		//加密
		void encrypt(std_byte* in, std_word* w);
		//解密
		void decrypt(std_byte* in, std_word* w);
	};
}





