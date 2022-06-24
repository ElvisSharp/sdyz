#include <map>
#include <vector>
#include <string>
#include <sdyz/arg_parser/arg_vec.hpp>
#include <sdyz/plus/str_plus.hpp>
#include <sdyz/exception/exception_pack.hpp>
#include <sdyz/arg_parser/exception.hpp>
#include <sdyz/arg_parser/arg_parser.hpp>

namespace sdyz
{
	//3个参数必须在一开始全部初始化（命令总数，命令与其编号的对应表）
	arg_parser::arg_parser(
		size_t _Cmd_Total_Amount,
		const opt_map* _Base_Opt_Set,
		size_t _Default_Cmd_Start_Index)
		:vector<arg_vec>(_Cmd_Total_Amount),
		cmd_amount_(_Cmd_Total_Amount),
		base_opt_set_(_Base_Opt_Set),
		default_cmd_start_index_(_Default_Cmd_Start_Index)
	{

	}
	arg_parser::~arg_parser()
	{
	}

	//处理所有命令行参数，需要在构造后使用
	void arg_parser::process_command(int _Argc, char** _Argv)
	{
		int argc = _Argc;
		char** argv = _Argv;
		size_t currentCmd = default_cmd_start_index_;
		//由于默认的下标开始是-1，所以如果改变了则说明存在默认下标
		if (default_cmd_start_index_ != SDYZ_DEFAULT_CMD_START_INDEX)
		{
			operator[](currentCmd).set_cmd_exists();
		}
		program_name_ = argv[0];
		for (int i = 1; i < argc; ++i)
		{
			//如果是命令
			if (is_start_with(argv[i], SDYZ_ARG_OPT_PREFIX))
			{
				//如果命令存在
				if (base_opt_set_->find(argv[i]) != base_opt_set_->end())
				{
					currentCmd = base_opt_set_->find(argv[i])->second;
					operator[](currentCmd).set_cmd_exists();
				}
				else
				{
					throw Invalid_Arguments(__func__);
				}
			}
			//是参数则添加到对应的命令下
			else
			{
				try
				{
					//若下标不合法，则转换异常
					operator[](currentCmd) << argv[i];
				}
				catch (std::exception&)
				{
					throw Invalid_Default_Cmd_Start_Index(__func__);
				}
			}
		}
		return;
	}

	string arg_parser::get_program_name()const
	{
		return program_name_;
	}

	const arg_vec& arg_parser::operator[](size_t _Index) const
	{
		if (_Index >= cmd_amount_)
		{
			throw Array_Index_Out_Of_Bounds_Exception(__func__);
		}
		return std::vector<arg_vec>::operator[](_Index);
	}

	arg_vec& arg_parser::operator[](size_t _Index)
	{
		if (_Index >= cmd_amount_)
		{
			throw Array_Index_Out_Of_Bounds_Exception(__func__);
		}
		return std::vector<arg_vec>::operator[](_Index);
	}
};
