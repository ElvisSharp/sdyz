#include <iostream>
#include <sdyz/exception/exception_pack.hpp>


int main()
{
	try
	{
		throw sdyz::Arithmetic_Execption(__func__);
	}
	catch (const sdyz::base_exception& _e)
	{
		std::cerr << _e << std::endl;
		exit(-1);
	}
	catch (const std::exception& _e)
	{
		std::cerr << _e.what() << std::endl;
		exit(-1);
	}
	return 0;
}
