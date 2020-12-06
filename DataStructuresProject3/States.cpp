#include "States.h"


//created so you can instantiate a states object to call the readCSV function
//Might move readCSV and maps elsewhere for modularity and separation of tasks
States::States() {};

States::States(string state, int voterCapacity, int numDistricts, string demSenator, string repSenator, int electoralVotes) {
	this->state = state;
	this->voterCapacity = voterCapacity;
	this->numDistricts = numDistricts;
	this->demSenator = demSenator;
	this->repSenator = repSenator;
	this->electoralVotes = electoralVotes;
}

States::States(const States& s)
{
	this->state = s.state;
	this->voterCapacity = s.voterCapacity;
	this->numDistricts = s.numDistricts;
	this->demSenator = s.demSenator;
	this->repSenator = s.repSenator;
	this->electoralVotes = s.electoralVotes;
	this->democratPresVotes = s.democratPresVotes;
	this->republicanPresVotes = s.republicanPresVotes;
	this->otherPresVotes = s.otherPresVotes;
	this->democratSenVotes = s.democratSenVotes;
	this->republicanSenVotes = s.republicanSenVotes;
	this->otherSenVotes = s.otherSenVotes;
}

//A bunch of get and set functions for variables in this class
string States::getState() {
	return this->state;
}

string States::getDemSenator() {
	return this->demSenator;
}

string States::getRepSenator() {
	return this->repSenator;
}

int States::getNumDistricts() {
	return this->numDistricts;
}

int States::getVoterCapacity() {
	return this->voterCapacity;
}

int States::getElectoralVotes() {
	return this->electoralVotes;
}

int States::getDemPresVotes()
{
	return democratPresVotes;
}
int States::getRepPresVotes()
{
	return republicanPresVotes;
}
int States::getOtherPresVotes()
{
	return otherPresVotes;
}
int States::getDemSenVotes()
{
	return democratSenVotes;
}
int States::getRepSenVotes()
{
	return republicanSenVotes;
}
int States::getOtherSenVotes()
{
	return otherSenVotes;
}

void States::setDemPresVotes(int v)
{
	this->democratPresVotes += v;
}

void States::setRepPresVotes(int v)
{
	this->republicanPresVotes += v;
}

void States::setOtherPresVotes(int v)
{
	this->otherPresVotes += v;
}

void States::setDemSenVotes(int v)
{
	this->democratSenVotes += v;
}

void States::setRepSenVotes(int v)
{
	this->republicanSenVotes += v;
}

void States::setOtherSenVotes(int v)
{
	this->otherSenVotes += v;
}

void States::addDemVotes(int voteCount, int districtNumber)
{
	setDemPresVotes(voteCount);
	setDemSenVotes(voteCount);
	this->districtMap[districtNumber].addVotersDem(voteCount);
}

void States::addRepVotes(int voteCount, int districtNumber)
{
	setRepPresVotes(voteCount);
	setRepSenVotes(voteCount);
	this->districtMap[districtNumber].addVotersRep(voteCount);
}

void States::addOtherVotes(int voteCount, int districtNumber)
{
	setOtherPresVotes(voteCount);
	setOtherSenVotes(voteCount);
	this->districtMap[districtNumber].addVotersOther(voteCount);
}


Voter::party States::determineWinner() {
	if (democratPresVotes > republicanPresVotes)
		return Voter::party::DEM;
	else
		return Voter::party::REP;
}




float States::getPercent(int num)
{
	if (num == 0)
	{
		return 100*(float)democratPresVotes / (float)voterCapacity;
	}
	else if (num == 1)
	{
		return 100*(float)republicanPresVotes / (float)voterCapacity;
	}
	else if (num == 2)
	{
		return 100*(float)otherPresVotes / (float)voterCapacity;
	}
	else if (num == 3)
	{
		return 100*(float)democratSenVotes / (float)voterCapacity;
	}
	else if (num == 4)
	{
		return 100*(float)republicanSenVotes / (float)voterCapacity;
	}
	else if (num == 5)
	{
		return 100*(float)otherSenVotes / (float)voterCapacity;
	}
}

void States::districtInfo()
{	
	for (int i = 1; i < this->numDistricts+1; i++)
	{
		cout << "\nRepresentative Election Data for district " << i << " in " << this->state << ": " << endl;
		printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f \n", districtMap[i].getDemocrat().c_str(), districtMap[i].getVotersDem(), districtMap[i].getPercent(6));
		printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f \n", districtMap[i].getRepublican().c_str(), districtMap[i].getVotersRep(), districtMap[i].getPercent(7));
		printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f \n", districtMap[i].getVotersOther(), districtMap[i].getPercent(8));
	}
}





