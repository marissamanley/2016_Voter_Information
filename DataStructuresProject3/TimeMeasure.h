#pragma once
#include "DataHandler.h";
#include "States.h";
#include "Districts.h";
#include "Tree.h";
#include "TreeNode.h";
#include <chrono>
using namespace std;

class TimeMeasure
{
	Tree* stateMapTree = DataHandler::stateTree;
	double timeMapInsert;
	double timeTreeInsert;
	unordered_map <string, States> stateMapMap = DataHandler::stateMap;
	TimeMeasure();
	void compareStructures();
	void updateTimeTreeInsert(double t);
	void updateTimeMapInsert(double t);
	double getTimeTreeInsert();
	double getTimeMapInsert();
};

