#include <sdyz/console/console.hpp>
#include <thread>

int main()
{
	unsigned long cur_rate = 0;
	sdyz::progress_bar bar(&cur_rate);
	std::thread t(bar);
	for (size_t i = 0; i <= 100; i++)
	{
		cur_rate = i*2;
		for (size_t j = 0; j < 10000000; j++);
	}
	t.join();
	return 0;
}