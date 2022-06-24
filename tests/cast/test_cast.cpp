#include <sdyz/cast/cast.hpp>
#include <iostream>

using namespace sdyz;
using std::string;

int main()
{
	string s1 = "-319";
	string s2 = "+86";
	string s3 = "+86";
	std::cout << cast<string, int>(s1) << std::endl;
	std::cout << cast<string, int>(s2) << std::endl;
	std::cout << cast<string, int>(s3) << std::endl;
}