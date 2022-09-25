#pragma once
#include "DataHandler.h"
#include "States.h"
#include "Districts.h"
#include "Tree.h"
#include "TreeNode.h"
#include "DataHandler.h"
#include "StoringData.h"
#include <chrono>
//  The function comparison class
//* This function is used to get a time comparison between
//* the unordered map and AVL tree. Time is measured for
//* insertion, search, and traversal operations and then
//* output.
class TimeMeasure {
public:
	std::string states[50] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware",
		"Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana",
	   "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska",
	   "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio",
	   "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah",
	   "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" };
	double timeMapInsert = 0.0;
	double timeTreeInsert = 0.0;
	double timeMapTraversal = 0.0;
	double timeTreeTraversal = 0.0;
	void compareStructures();

};

