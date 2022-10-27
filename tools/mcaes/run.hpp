#pragma once
#include <sdyz/vector/byte_vector.hpp>
#include <sdyz/algorithm/cryptography/aes/aes.hpp>
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

void printHelpInfo();
void run(int _Argc, char** _Argv);
