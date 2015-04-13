#include "timer.h"

void Timer::start()
{
	timer = steady_clock::now();
}

void Timer::stop()
{
	durations.push_back(steady_clock::now() - timer);
}

double Timer::getAverage()
{
	return getTotal() / durations.size();
}

double Timer::getTotal()
{
	double total = 0;
	for (int i = 0; i < durations.size(); i++)
	{
		total += duration_cast<milliseconds>(durations[i]).count();
	}
	return total;
}

void Timer::printAverage()
{
	std::cout << "Average time taken " << getAverage() << " ms" << std::endl;
}

void Timer::printTotal()
{
	std::cout << "Total time taken " << getTotal() << " ms" << std::endl;
}

void Timer::clear()
{
	durations.clear();
}