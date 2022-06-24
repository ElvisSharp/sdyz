#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

#include <sdyz/cast/cast.hpp>
#include <sdyz/tools/ask_ans.hpp>

namespace sdyz
{

	ask_ans::ask_ans()
		: now_pos(0),
		is_all_ok(false),
		in_stream_(std::cin),
		out_stream_(std::cout)
	{
	}

	ask_ans::~ask_ans()
	{
	}

	void ask_ans::operator<<(const std::string& _Str)
	{
		std::string tmp_str;
		if (!is_all_ok)
		{
			out_stream_ << _Str;
			in_stream_ >> tmp_str;
		}
		else
		{
			tmp_str = "y";
		}
		push_back(tmp_str);
		now_pos = size() - 1;
		return;
	}

	std::string ask_ans::get_res_string() const
	{
		return get_res_string(now_pos);
	}

	std::string ask_ans::get_res_string(size_t _Pos) const
	{
		return operator[](_Pos);
	}

	bool ask_ans::get_res_bool() const
	{
		return get_res_bool(now_pos);
	}

	bool ask_ans::get_res_bool(size_t _Pos) const
	{
		std::string res = get_res_string(_Pos);
		if (res[0] == 'y' || res[0] == 'Y')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int ask_ans::get_res_long() const
	{
		return get_res_long(now_pos);
	}

	int ask_ans::get_res_long(size_t _Pos) const
	{
		std::string tmp = get_res_string(_Pos);
		return cast<std::string, int>(tmp);
	}

	void ask_ans::all_accept()
	{
		is_all_ok = true;
		return;
	}

	void ask_ans::not_all_accept()
	{
		is_all_ok = false;
		return;
	}

};
