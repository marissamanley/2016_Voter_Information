#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Districts.h"
using namespace std;

class States
{
private:
	string state;
	int voterCapacity;
	int numDistricts;
	map<string, vector<Districts>> states;

public:
	States(string state, int voterCapacity, int numDistricts);
	void readCSV(string filePath);
};

