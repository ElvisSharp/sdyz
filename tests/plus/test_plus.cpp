#include <string>
#include <iostream>
#include <sdyz/plus/str_plus.hpp>
#include <sdyz/plus/file_plus.hpp>
#include <sdyz/plus/rand_plus.hpp>
using namespace std;

int main()
{
	//测试str_plus
	string string1 = "ykugcsdyz";
	cout << "res_1:" << sdyz::is_end_with(string1, "csdyz") << endl;
	cout << "res_2:" << sdyz::is_start_with(string1, "yku") << endl;
	//测试file_plus
	cout << "size:"
		<< sdyz::get_size("A90623312F4CD43D4144A5EF8A47602D")
		<< endl;
	//测试rand_plus
	cout << sdyz::rand01();
	return 0;
}
