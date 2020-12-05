#pragma once
#include "Districts.h"
#include "States.h"
#include "Tree.h"
#include "TreeNode.h"
#include "Voter.h"

/*
 * The purpose of this class is to initialize the data from the CSV file and store it within unordered_maps
 * Class can potentially be used for taking in and holding election results

 * stateMap:
 *	- Assigns each state object (that holds all of the above information) to a numeric value
 *
 * districtMap
 *	- Assigns the name of each state to a vector of District objects that are within that state
 *
 * readCSV initializes these maps
 */

class DataHandler
{
private:
	static void readCSV(string filePath, int offset = 0);
	static void createVoters();
public:
	static void initData();
	static unordered_map<string, States> stateMap;
    static Tree* stateTree;
};

