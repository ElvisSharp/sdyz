#include <exception>
#include <iostream>
#include "exception.hpp"
#include "run.hpp"

int main(int argc, char** argv)
{
	try
	{
		run(argc, argv);
	}
	catch (const std::exception& _E)
	{
		std::cerr << _E.what() << std::endl;
		exit(-1);
	}
	return 0;
}
