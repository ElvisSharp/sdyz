/*********************************************************
*"console"包含了一些控制台的组件
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#pragma once
#include <cstdio>

namespace sdyz
{
#define SDYZ_PROGRESS_BAR_TOTAL 100

	class progress_bar
	{
	public:
		static const char progress_bar_format_[SDYZ_PROGRESS_BAR_TOTAL + 1];

	public:
		progress_bar();

		progress_bar(unsigned long* _Rate);

		~progress_bar();

	private:
		//当前的进度
		unsigned long current_rate_;
		//绑定的进度
		unsigned long* bind_rate_;
		//输出流
		FILE* output_stream_;

	public:
		//绑定进度
		void bind_rate(unsigned long* _Rate);

	public:
		//使用异步的打印，支持多线程
		void operator()();

	};

}