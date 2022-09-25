#pragma once
//This class is made to make the process of obtaining
//time data smoother
class StoringData {
public:
	double timeMapIns = 0.0;
	double timeTreeIns = 0.0;
	double timeMapTravers = 0.0;
	double timeTreeTravers = 0.0;

	void updateTimeMapIns(double t);
	void updateTimeTreeIns(double t);
};

