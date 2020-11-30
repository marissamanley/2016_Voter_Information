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
 * 
 * This class also contains the stateMap and districtMap maps
 * stateMap:
 *	- Assigns each state object (that holds all of the above information) to a numeric value
 * 
 * districtMap
 *	- Assigns the name of each state to a vector of District objects that are within that state
 * 
 * readCSV initializes these maps
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
	//make unordered_map instead
	//change key from int to string
	static unordered_map<string, States> stateMap;
	static unordered_map<string, vector<Districts>> districtMap;
	unordered_map<int, Districts> districtMapTwo;

	States();
	States(string state, int voterCapacity, int numDistricts, string demSenator, string repSenator, int electoralVotes);
	void readCSV(string filePath, int offset = 0);

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

