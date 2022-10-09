#include <sdyz/console/console.hpp>

int main()
{
	unsigned long cur_rate = 0;
	sdyz::progress_bar bar;
	printf("%s\n", "Test sdyz::progress_bar");
	for (size_t i = 0; i <= 100; i++)
	{
		cur_rate = i;
		for (size_t j = 0; j < 100000000; j++);
		bar.set_current_rate(cur_rate);
	}
	bar.end_progress_bar();
	printf("%s\n", "The end of test");
	return 0;
}