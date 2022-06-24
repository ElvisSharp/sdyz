#include <iostream>
#include <map>
#include <sdyz/arg_parser/arg_parser.hpp>

enum index
{
	ONE = 0,
	TWO,
	THREE
};

sdyz::opt_map optset{
		{ "-ord1", ONE },
		{ "-ord2", TWO },
		{ "-ord3", THREE },
};

void run(
	int _Argc,
	char** _Argv,
	size_t _CmdCount,
	const sdyz::opt_map* _BaseOptSet,
	size_t _ArgvCmdStart)
{
	sdyz::arg_parser ac(_CmdCount, _BaseOptSet, _ArgvCmdStart);
	ac.process_command(_Argc, _Argv);
	for (int i = ONE; i <= THREE; ++i)
	{
		for (int j = 0; j < ac[i].size(); ++j)
		{
			std::cout << ac[i][j] << std::endl;
		}
	}
}

int main(int argc, char** argv)
{
	try
	{
		run(argc, argv, 3, &optset, ONE);
	}
	catch (const std::exception& _e)
	{
		std::cerr << _e.what() << std::endl;
		exit(-1);
	}
	return 0;
}
