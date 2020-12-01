#pragma once
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Districts.h"
using namespace std;

/*
 * This class hold information about each state. The information held is:
 *  - State name
 *  - Number of voters in the state
 *  - Number of districts within the state
 *  - Names of the senators running for office (have not accounted for multiple senate races yet)
 *  - Number of votes the state has in the electoral college
 */
//hi


class States
{
private:
	string state;
	int voterCapacity;
	int numDistricts;
	string demSenator;
	string repSenator;
	int electoralVotes;
	float percentDemPres;
	float percentRepPres;
	float percentOtherPres;
	float percentDemSen;
	float percentRepSen;
	float percentOtherSen;

public:
	
	static unordered_map<int, Districts> districtMap;

	States();
	States(string state, int voterCapacity, int numDistricts, string demSenator, string repSenator, int electoralVotes);

	string getState();
	string getDemSenator();
	string getRepSenator();
	int getVoterCapacity();
	int getNumDistricts();
	int getElectoralVotes();
	float getPerDemPres();
	float getPerRepPres();
	float getPerOtherPres();
	float getPerDemSen();
	float getPerRepSen();
	float getPerOtherSen();
	void setPerDemPres(float f);
	void setPerRepPres(float f);
	void setPerOtherPres(float f);
	void setPerDemSen(float f);
	void setPerRepSen(float f);
	void setPerOtherSen(float f);
};

