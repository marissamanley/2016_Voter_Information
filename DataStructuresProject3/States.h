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
#include "Voter.h"
using namespace std;

/*
 * This class hold information about each state. The information held is:
 *  - State name
 *  - Number of voters in the state
 *  - Number of districts within the state
 *  - Names of the senators running for office (have not accounted for multiple senate races yet)
 *  - Number of votes the state has in the electoral college
 *	- Names for each candidate
 *  - Number of cast votes for this state
 * 
 * districtMap:
 *  - Each state holds their district within a unordered map
 *	- Key: district number
 *	- Value: District object
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
	unordered_map<int, Districts> districtMap;

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

	void setDemPresVotes(int v);
	void setRepPresVotes(int v);
	void setOtherPresVotes(int v);
	void setDemSenVotes(int v);
	void setRepSenVotes(int v);
	void setOtherSenVotes(int v);
	void addDemVotes(int voteCount, int districtNumber);
	void addRepVotes(int voteCount, int districtNumber);
	void addOtherVotes(int voteCount, int districtNumber);

	Voter::party determineWinner();

	float getPercent(int num);
	void districtInfo();
};

