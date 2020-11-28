#pragma once
#include <string>
using namespace std;

class Districts
{
private:
	int district;
	int voterCapacity;
	float percentDem;
	float percentRep;
	float percentOther;
	string democrat;
	string republican;

public:
	Districts(int district, int voterCapacity, float percentDem, float percentRep, string democratRep, string republicanRep);
	int getDistrict();
	void setDistrict(int district);

	int getVoterCapacity();
	void setVoterCapacity(int voterCapacity);

	float getPercentDem();
	void setPercentDem(float percentDem);

	float getPercentRep();
	void setPercentRep(float percentDem);

	float getPercentOther();
	void setPercentOther(float percentOther);

	string getDemocrat();
	void setDemocrat(string dem);

	string getRepublican();
	void setRepublican(string rep);
};

