#include <string>
#include <vector>
#include <sdyz/exception/exception_pack.hpp>
#include <sdyz/arg_parser/exception.hpp>
#include <sdyz/arg_parser/arg_vec.hpp>

namespace sdyz
{

	arg_vec::arg_vec() :
		vector<string>(),
		exist_flag(false)
	{
	}

	arg_vec::arg_vec(const arg_vec& _Arg_Vec)
	{
		operator=(_Arg_Vec);
	}

	arg_vec::~arg_vec()
	{
	}

	//该命令是否出现
	bool arg_vec::cmd_exists() const
	{
		return exist_flag;
	}

	//标记该命令，将其设置为已经出现
	void arg_vec::set_cmd_exists()
	{
		exist_flag = true;
		return;
	}

	//标记该命令，将其设置为未出现
	void arg_vec::set_cmd_not_exists()
	{
		exist_flag = false;
		return;
	}

	//向对象中加入命令之后的参数，例如：[--option] [argv]
	arg_vec& arg_vec::operator<<(const string& _Argv)
	{
		push_back(_Argv);
		return (*this);
	}

	//重载vector的[]，通过index来找到对应的参数
	const string& arg_vec::operator[](size_t _Index) const
	{
		if (_Index >= size())
		{
			throw Array_Index_Out_Of_Bounds_Exception(__func__);
		}
		return vector<string>::operator[](_Index);
	}

	string& arg_vec::operator[](size_t _Index)
	{
		if (_Index >= size())
		{
			throw Array_Index_Out_Of_Bounds_Exception(__func__);
		}
		return vector<string>::operator[](_Index);
	}
};
