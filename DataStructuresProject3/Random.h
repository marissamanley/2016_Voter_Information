#pragma once
#include <random>
#include <ctime>
class Random
{
private:
	static std::mt19937 random;
public:
	static int Int(int min, int max);
	static int Float(float min, float max);
};

