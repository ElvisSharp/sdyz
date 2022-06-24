/*********************************************************
*"arg_parser"是管理命令行参数的类
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

/*
* 基本信息：
* arg_parser是管理命令行参数的类
* arg_parser是不可被拷贝复制的
* 命令行参数（arg）：使用命令行传入程序的参数的统称
* 命令名（arg_opt）：以“-”开始，表示某一功能
* 默认命令名：一定会出现，且在顺序解析时，如果第一个命令行参数是命令参数，
* 则会被自动解析到默认命令名对应的vector下
* 命令参数(arg)：不以“-”开头，跟在命令名后，表示一些参数
* cmd_amount_（size_t）是所有命令的个数
* base_opt_set_是一张基本的查询表（map<string, size_t>），
* 对应了命令名与其对应的命令编号（<命令名，命令参数>），需要由用户来初始化
* 命令名编号一定从0开始，建议使用宏定义或枚举类型
* 程序会将参数都保存在对应命令下标的vector中
* 若第一个命令行参数并不是命令名，则一定需要设置默认命令名的下标：default_cmd_start_index_，
* 如果没有初始化该项，则程序会找不到默认的参数vector，导致程序异常
*/


#pragma once

#include <map>
#include <vector>
#include <string>
#include <sdyz/arg_parser/arg_vec.hpp>
#include <sdyz/plus/str_plus.hpp>
#include <sdyz/exception/exception_pack.hpp>
#include <sdyz/arg_parser/exception.hpp>

//没有默认的参数下标开始，就将其置为-1
#define SDYZ_DEFAULT_CMD_START_INDEX -1
#define SDYZ_ARG_OPT_PREFIX "-"

namespace sdyz
{
	typedef std::map<string, size_t> opt_map;

	class arg_parser :public std::vector<arg_vec>
	{
	protected:
		//命令行命令的总数
		const size_t cmd_amount_;
		//需要自定义的map
		const opt_map* base_opt_set_;
		//默认开始的命令行命令下标
		const size_t default_cmd_start_index_;
		//调用的程序名
		string program_name_;

	public:
		//空参构造无任何实际意义
		arg_parser() = delete;

		//3个参数必须在一开始全部初始化（命令总数，命令与其编号的对应表）
		arg_parser(
			size_t _Cmd_Total_Amount,
			const opt_map* _Base_Opt_Set = NULL,
			size_t _Default_Cmd_Start_Index = SDYZ_DEFAULT_CMD_START_INDEX);

		//禁止复制及拷贝
		arg_parser(const arg_parser& _Argv_Parser) = delete;

		~arg_parser();

		//处理所有命令行参数，需要在构造后使用
		void process_command(int _Argc, char** _Argv);

		string get_program_name()const;

	public:
		//禁止复制及拷贝
		const arg_parser& operator=(const arg_parser& _Argv_Parser) = delete;

		const arg_vec& operator[](size_t _Index) const;

		arg_vec& operator[](size_t _Index);
	};
};
