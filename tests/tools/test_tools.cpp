#include <iostream>

#include <sdyz/tools/ask_ans.hpp>
#include <sdyz/tools/numeration.hpp>

int main()
{
	//测试ask_ans类
	sdyz::ask_ans aa;
	aa << "(y/n)?";
	bool b = aa.get_res_bool();
	std::cout << b << std::endl;
	//测试numeration类
	sdyz::numeration n(234028);
	std::cout << n.to_string(16) << std::endl;
	std::cout << n.to_string(8) << std::endl;
	std::cout << n.to_string(2) << std::endl;
	n.set(16, "7F2E1");
	std::cout << n.to_string(16) << std::endl;
	std::cout << n.to_string(10) << std::endl;
	std::cout << n.to_string(8) << std::endl;
	std::cout << n.to_string(2) << std::endl;
	return 0;
}