#pragma once
//This class is made simply to make the process of obtaining
//time data smoother
class StoringData
{
public:
	double timeMapIns = 0.0;
	double timeTreeIns = 0.0;
	double timeMapTravers = 0.0;
	double timeTreeTravers = 0.0;

	void updateTimeMapIns(double t)
	{
		//keeps only the largest value of insertion time
		if (t > timeMapIns)
		{
			timeMapIns = t;
		}
	}
	void updateTimeTreeIns(double t)
	{
		//keeps only the largest value of insertion time
		if (t > timeTreeIns)
		{
			timeTreeIns = t;
		}
	}
};

