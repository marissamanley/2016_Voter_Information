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
	int voterCapacity = 0;
	int numDistricts = 0;
	string demSenator;
	string repSenator;
	int electoralVotes = 0;
	int democratPresVotes = 0;
	int republicanPresVotes = 0;
	int otherPresVotes = 0;
	int democratSenVotes = 0;
	int republicanSenVotes = 0;
	int otherSenVotes = 0;

public:
	
	static unordered_map<int, Districts> districtMap;

	States();
	States(string state, int voterCapacity, int numDistricts, string demSenator, string repSenator, int electoralVotes);
	States(const States& s);
	string getState();
	string getDemSenator();
	string getRepSenator();
	int getVoterCapacity();
	int getNumDistricts();
	int getElectoralVotes();
	int getDemPresVotes();
	int getRepPresVotes();
	int getOtherPresVotes();
	int getDemSenVotes();
	int getRepSenVotes();
	int getOtherSenVotes();
	void addDemPresVotes(int i);
	void addRepPresVotes(int i);
	void addOtherPresVotes(int i);
	void addDemSenVotes(int i);
	void addRepSenVotes(int i);
	void addOtherSenVotes(int i);
	float getPercent(int num);
};

