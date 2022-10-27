#pragma once
#include <sdyz/vector/byte_vector.hpp>
#include <sdyz/algorithm/cryptography/des/des.hpp>
#include <sdyz/arg_parser/arg_parser.hpp>
#include <iostream>

using namespace sdyz;
using namespace std;

enum class OPT
{
	HELP = 0,
	EN,
	DE,
	INPUT,
	BASEKEY,
	KEY
};

#define OPT_TOTAL_AMOUNT 6
extern const opt_map opt_set;

byte_vector rand_byte_vector(size_t _Size);
void printHelpInfo();
void run(int _Argc, char** _Argv);
