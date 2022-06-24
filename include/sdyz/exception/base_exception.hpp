/*********************************************************
*"base_exception"中保存了基础的异常类的声明
*作者：丁瀛洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#pragma once

#include <iostream>
#include <string>
#include <exception>

#define SDYZ_UNKNOWN_ERROR_CODE -1
#define SDYZ_UNKNOWN_POSITION "未知的位置"

namespace sdyz
{

	class base_exception : public std::exception
	{
	private:
		//错误代码
		const size_t error_code;

		//错误消息
		const std::string error_message;

		//错误位置
		const std::string error_pos;

		//整合后的消息
		mutable char* error_what;


	public:
		base_exception()
			: error_code(SDYZ_UNKNOWN_ERROR_CODE),
			error_message(""),
			error_pos(SDYZ_UNKNOWN_POSITION),
			error_what(nullptr)
		{
		}

		base_exception(int _Error_Code, const char* _Message)
			: error_code(_Error_Code),
			error_message(_Message),
			error_pos(SDYZ_UNKNOWN_POSITION),
			error_what(nullptr)
		{
		}

		base_exception(int _Error_Code, const char* _Message, const char* _Position)
			: error_code(_Error_Code),
			error_message(_Message),
			error_pos(_Position),
			error_what(nullptr)
		{
		}

		~base_exception()
		{
			if (error_what)
			{
				delete[] error_what;
			}
		}

		virtual const
			char* what() const noexcept
		{
			std::string res = std::to_string(error_code) + "::" + \
				error_message + "::" + \
				error_pos;
			size_t size = res.size();
			if (error_what)
			{
				delete[] error_what;
			}
			error_what = new char[size + 1];
			res.copy(error_what, size);
			error_what[size] = 0;
			return error_what;
		}
	};

	std::ostream& operator<<(std::ostream& _Oerr,
		const base_exception& _Exception);

};

