/*********************************************************
*"arg_vec"是管理命令行参数的类
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#pragma once
#include <string>
#include <vector>
#include <sdyz/exception/exception_pack.hpp>
#include <sdyz/arg_parser/exception.hpp>

namespace sdyz
{
	typedef std::string string;

	//整个arg_vec都是继承于std::vector<string>的
	class arg_vec : public std::vector<string>
	{
	protected:
		//该命令是否出现，默认为False
		bool exist_flag;

	public:
		arg_vec();

		arg_vec(const arg_vec& _Arg_Vec);

		~arg_vec();

	public:
		//该命令是否出现
		bool cmd_exists() const;

		//标记该命令，将其设置为已经出现
		void set_cmd_exists();

		//标记该命令，将其设置为未出现
		void set_cmd_not_exists();

	public:
		//向对象中加入命令之后的参数，例如：[--option] [argv]
		arg_vec& operator<<(const string& _Argv);

		//重载vector的[]，通过index来找到对应的参数
		const string& operator[](size_t _Index) const;

		string& operator[](size_t _Index);
	};
};
