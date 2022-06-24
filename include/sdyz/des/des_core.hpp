#pragma once
#include <iostream>
#include <bitset>

namespace sdyz
{
	namespace des_core
	{
		typedef std::bitset<64> Block;
		typedef std::bitset<56> Key;
		typedef std::bitset<48> Code;

		typedef std::bitset<32> Half_block;
		typedef std::bitset<28> Half_key;
		typedef std::bitset<24> Half_code;

		typedef enum
		{
			e,
			d
		} Method;

		int ip(const Block& block, Half_block& left, Half_block& right);
		int des_turn(Half_block& left, Half_block& right, const Code& subkey);
		int exchange(Half_block& left, Half_block& right);
		int rip(const Half_block& left, const Half_block& right, Block& block);
		Code getkey(const unsigned int n, const Block& bkey);
		int des(Block& block, Block& bkey, const Method method);
	}
}