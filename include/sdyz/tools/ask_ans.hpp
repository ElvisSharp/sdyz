/*********************************************************
*"ask_ans"是用于交互问答操作的类
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

#include <sdyz/cast/cast.hpp>

namespace sdyz
{

	class ask_ans
		: public std::vector<std::string>
	{
	private:
		size_t now_pos;
		bool is_all_ok;
		std::istream& in_stream_;
		std::ostream& out_stream_;

	public:
		ask_ans();

		~ask_ans();

	public:
		void operator<<(const std::string& _Str);

		std::string get_res_string() const;

		std::string get_res_string(size_t _Pos) const;

		bool get_res_bool() const;

		bool get_res_bool(size_t _Pos) const;

		int get_res_long() const;

		int get_res_long(size_t _Pos) const;

		void all_accept();

		void not_all_accept();
	};

};
