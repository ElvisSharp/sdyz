#include <sdyz/hash/sha1.hpp>
#include <sdyz/vector/byte_vector.hpp>
#include <iostream>

int main()
{
	std::cout << sdyz::sha1<std::string>("1234567890").to_hex_string() << std::endl;
	std::cout << sdyz::sha1<int>(144).to_hex_string() << std::endl;
	return 0;
}