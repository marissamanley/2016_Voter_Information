#pragma once
class StoringData
{
public:
	double timeMapIns = 0.0;
	double timeTreeIns = 0.0;
	double timeMapTravers = 0.0;
	double timeTreeTravers = 0.0;

	void updateTimeMapIns(double t)
	{
		if (t > timeMapIns)
		{
			timeMapIns = t;
		}
	}
	void updateTimeTreeIns(double t)
	{
		if (t > timeTreeIns)
		{
			timeTreeIns = t;
		}
	}
};

