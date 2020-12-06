#pragma once
#include "Districts.h"
#include "States.h"
#include "Tree.h"
#include "TreeNode.h"
#include "Voter.h"
using namespace std;
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
    static void calculateElectoralVotes();

public:
    string states[50] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware",
         "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana",
        "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska",
        "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio",
        "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah",
        "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" };
    
	static void initData();
	static unordered_map<string, States> stateMap;
    static Tree* stateTree;
    static int demElectoralVotes();
    static int repElectoralVotes();
    static int demElectors;
    static int repElectors;
};

