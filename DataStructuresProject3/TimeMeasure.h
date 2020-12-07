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

