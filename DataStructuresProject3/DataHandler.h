#pragma once
#include "Districts.h"
#include "States.h"
#include "Tree.h"
#include "TreeNode.h"
#include "Voter.h"
#include <chrono>
#include "TimeMeasure.h"
#include "StoringData.h"
using namespace std;
/*
 * The purpose of this class is to initialze and store all information in this project
 * All methods are static so they can be freely availale for use in any class
 * There is no need to instantiate this class, since all information will be constant in this project
 *
 * Methods:
 *	readCSV(): - Reads from a CSV file that contains information about each state
 *			   
 *	
 * creatVoters(): Generates 160,000 voters based on party demographics in each district
 *
 * ".../ElectoralVotes(): These set of functions calculate the party winner of each state, and assigns them the electoral votes for that state
 *
 * initData(): Calls on all of these functions to initialize all data used for the menu
 *
 * stateMap:
 *	- Key: Name of State
 *  - Value: State object that holds all information in state class
 *
 * stateTree:
 *	- Root of an AVL tree that holds state objects as their value
 *
 *
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
    static StoringData st;
    static int demElectoralVotes();
    static int repElectoralVotes();
    static int demElectors;
    static int repElectors;
};

