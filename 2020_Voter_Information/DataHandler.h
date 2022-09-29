#pragma once
#include "Districts.h"
#include "States.h"
#include "Tree.h"
#include "TreeNode.h"
#include "Voter.h"
#include <chrono>
#include "TimeMeasure.h"
#include "StoringData.h"
/*
 * The purpose of this class is to initialze and store all information in this project.
 * All methods are static so they can be freely available for use in any class.
 * There is no need to instantiate this class, since all information will be constant in this project.
 *
 * stateMap:
 *	- Key: Name of State
 *  - Value: State object that holds all information in state class
 *
 * stateTree:
 *	- Root of an AVL tree that holds state objects as their value
 *
 */
class DataHandler {
private:
	static void readCSV(std::string filePath, int offset = 0);
	static void createVoters();
    static void calculateElectoralVotes();

public:
	static void initData();
	static std::unordered_map<std::string, States> stateMap;
    static Tree* stateTree;
    static StoringData st;
    static int demElectors;
    static int repElectors;
};

