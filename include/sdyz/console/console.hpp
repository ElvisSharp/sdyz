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

		~progress_bar();

	private:
		//当前的进度
		unsigned long current_rate_;
		//输出流
		FILE* output_stream_;

	public:
		//设置当前值
		void set_current_rate(unsigned long _Current_Rate);
		
		//结束进度条
		void end_progress_bar();

	};

}