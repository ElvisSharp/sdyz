#define _CRT_SECURE_NO_WARNINGS

#include <sdyz/console/console.hpp>

namespace sdyz
{
	const char progress_bar::progress_bar_format_[SDYZ_PROGRESS_BAR_TOTAL + 1] =
			"====================================================================================================";

	progress_bar::progress_bar()
			: bind_rate_(NULL),
			  current_rate_(0),
			  output_stream_(stdout)
	{

	}

	progress_bar::progress_bar(unsigned long* _Rate)
			: bind_rate_(_Rate),
			  current_rate_(0),
			  output_stream_(stdout)
	{

	}

	progress_bar::~progress_bar()
	{

	}

	void progress_bar::bind_rate(unsigned long* _Rate)
	{
		bind_rate_ = _Rate;
		return;
	}

	void progress_bar::operator()()
	{
		if (!bind_rate_)
		{
			return;
		}
		const char* rotate_str = "-\\|/";
		//初始化打印进度条
		unsigned long out_format_offset =
				(current_rate_ > SDYZ_PROGRESS_BAR_TOTAL) ? SDYZ_PROGRESS_BAR_TOTAL : current_rate_;
		fprintf(output_stream_, "[%-100s][%2d%%][%c]",
				progress_bar_format_ + SDYZ_PROGRESS_BAR_TOTAL - out_format_offset,
				current_rate_,
				rotate_str[current_rate_ % 4]);
		fprintf(output_stream_, "\r");
		fflush(output_stream_);
		while (current_rate_ <= SDYZ_PROGRESS_BAR_TOTAL)
		{
			//进度没有改变就不重新打印
			while (*bind_rate_ == current_rate_);
			current_rate_ = *bind_rate_;
			out_format_offset =
					(current_rate_ > SDYZ_PROGRESS_BAR_TOTAL) ? SDYZ_PROGRESS_BAR_TOTAL : current_rate_;
			fprintf(output_stream_, "[%-100s][%2d%%][%c]",
					progress_bar_format_ + SDYZ_PROGRESS_BAR_TOTAL - out_format_offset,
					current_rate_,
					rotate_str[current_rate_ % 4]);
			fprintf(output_stream_, "\r");
			fflush(output_stream_);
			if (current_rate_ >= SDYZ_PROGRESS_BAR_TOTAL)
			{
				return;
			}
		}
		return;
	}
}
