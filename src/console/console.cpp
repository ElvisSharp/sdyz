#define _CRT_SECURE_NO_WARNINGS

#include <sdyz/console/console.hpp>

namespace sdyz
{
	const char progress_bar::progress_bar_format_[SDYZ_PROGRESS_BAR_TOTAL + 1] =
			"====================================================================================================";

	progress_bar::progress_bar()
			: current_rate_(0),
			  output_stream_(stdout)
	{
	}

	progress_bar::~progress_bar()
	{

	}

	void progress_bar::set_current_rate(unsigned long _Current_Rate)
	{
		// 设置当前值
		current_rate_ = _Current_Rate;
		const char* rotate_str = "-\\|/";
		// 初始化打印进度条
		// 计算偏移数
		unsigned long out_format_offset =
				(current_rate_ > SDYZ_PROGRESS_BAR_TOTAL) ? SDYZ_PROGRESS_BAR_TOTAL : current_rate_;
		fprintf(output_stream_, "[%-100s][%2d%%][%c]",
				progress_bar_format_ + SDYZ_PROGRESS_BAR_TOTAL - out_format_offset,
				current_rate_,
				rotate_str[current_rate_ % 4]);
		fprintf(output_stream_, "\r");
		fflush(output_stream_);
		return;
	}

	void progress_bar::end_progress_bar()
	{
		fprintf(output_stream_, "\n");
		return;
	}

}
