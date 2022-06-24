#include <sdyz/vector/byte_vector.hpp>
#include <iostream>
#include <fstream>
int main()
{
	try
	{
		//测试字符串到byte_vector的转换
		sdyz::byte_vector string_test = sdyz::to_byte_vector("三点一洲");
		std::cout << sdyz::to_string(string_test) << std::endl;
		std::cout << string_test.to_hex_string() << std::endl;
		//测试与运算
		sdyz::byte_vector and_test;
		and_test.set_by_hex_string("FFFFFFFFFFFFFFFF");
		std::cout << and_test.to_bin_string() << std::endl;
		and_test = and_test & string_test;
		std::cout << sdyz::to_string(and_test) << std::endl;
		sdyz::byte_vector stream_test;
		//测试byte_vector文件操作
		//std::ifstream ifs;
		//std::ofstream ofs;
		//ifs.open("test.in", std::ios::in | std::ios::binary);
		//ofs.open("test.out", std::ios::out | std::ios::binary);
		//ifs >> stream_test;
		//ofs << stream_test;
	}
	catch (const std::exception& _e)
	{
		std::cerr << _e.what() << std::endl;
		exit(-1);
	}
	return 0;
}
