#pragma once
#include "Districts.h"
#include "States.h"

/*
 * The purpose of this class is to initialize the data from the CSV file and store it within unordered_maps
 * These maps can be access from anywhere
 */

class DataHandler
{
private:
	static void readCSV(string filePath, int offset = 0);
public:
	DataHandler();
	static void initData();
	static unordered_map<string, States> stateMap;
	static unordered_map<string, vector<Districts>> districtMap;
};

