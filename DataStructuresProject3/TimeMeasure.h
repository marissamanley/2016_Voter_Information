#pragma once
#include "DataHandler.h"
#include "States.h"
#include "Districts.h"
#include "Tree.h"
#include "TreeNode.h"
#include "DataHandler.h"
#include "StoringData.h"
#include <chrono>
using namespace std;
//  The function comparison class
//* This function is used to get a time comparison between
//* the unordered map and AVL tree. Time is measured for
//* insertion, search, and traversal operations and then
//* output.
class TimeMeasure
{
public:
	Tree* stateMapTree;
	double timeMapInsert = 0.0;
	double timeTreeInsert = 0.0;
	double timeMapTraversal = 0.0;
	double timeTreeTraversal = 0.0;
	unordered_map <string, States> stateMapMap;
	TimeMeasure();
	void compareStructures();
	void updateTimeTreeInsert(double t);
	void updateTimeMapInsert(double t);
	void setTimeTreeTraversal(double t);
	void setTimeMapTraversal(double t);
	double getTimeTreeInsert();
	double getTimeMapInsert();
	double getTimeTreeTraversal();
	double getTimeMapTraversal();
};

