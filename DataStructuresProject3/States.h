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
	string demSenator;
	string repSenator;

public:
	static map<int, States> stateMap;
	static map<string, vector<Districts>> districtMap;

	States();
	States(string state, int voterCapacity, int numDistricts, string demSenator, string repSenator);
	void readCSV(string filePath, int offset);

	string getState();
	string getDemSenator();
	string getRepSenator();
	int getVoterCapacity();
	int getnumDistricts();
};

