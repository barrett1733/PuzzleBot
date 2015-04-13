#pragma once
#include <chrono>
#include <vector>
#include <iostream>

using namespace std::chrono;

class Timer
{
	steady_clock::time_point timer, average, total;
	std::vector<steady_clock::duration> durations;
public:
	void start();
	void stop();
	double getAverage();
	double getTotal();
	void printAverage();
	void printTotal();
	void clear();
};

