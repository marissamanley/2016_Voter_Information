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
	int electoralVotes;

public:
	static map<int, States> stateMap;
	static map<string, vector<Districts>> districtMap;

	States();
	States(string state, int voterCapacity, int numDistricts, string demSenator, string repSenator, int electoralVotes);
	void readCSV(string filePath, int offset = 0);

	string getState();
	string getDemSenator();
	string getRepSenator();
	int getVoterCapacity();
	int getNumDistricts();
	int getElectoralVotes();
};

