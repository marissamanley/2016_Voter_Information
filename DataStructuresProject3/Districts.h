#pragma once
#include <string>
using namespace std;

/*
 * This class holds information about each district. The information helds is:
 *	- District number
 *	- Number of voters
 *  - Names of the candidates for the US House of Representatives
 *	- Makeup of the party representation within the district
 *		- This is based off of the votes for the 2020 election
 * 
 * Districts are not meant to exist on their own. They exist within a list for each state.
 * All votes are cast at the district level, thus the senate and national election results will be 
 * by each districts party representation, rather than a representation existing for each state.
 * This is balanced by each district having its own number of voters, with its size related to the districts actual size
 */

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
	Districts() {};
	Districts(int district, int voterCapacity, float percentDem, float percentRep, string democratRep, string republicanRep);

	//set functions there for potential modularity 
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

