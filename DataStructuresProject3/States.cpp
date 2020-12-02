#include "States.h"

unordered_map<int, Districts> States::districtMap;

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

void States::setDemPresVotes(int i)
{
	democratPresVotes = i;
}

void States::setRepPresVotes(int i)
{
	republicanPresVotes = i;
}

void States::setOtherPresVotes(int i)
{
	otherPresVotes = i;
}

void States::setDemSenVotes(int i)
{
	democratSenVotes = i;
}

void States::setRepSenVotes(int i)
{
	republicanSenVotes = i;
}

void States::setOtherSenVotes(int i)
{
	otherSenVotes = i;
}

float States::getPercent(int num)
{
	if (num == 0)
	{
		return (float)democratPresVotes / (float)voterCapacity;
	}
	else if (num == 1)
	{
		return (float)republicanPresVotes / (float)voterCapacity;
	}
	else if (num == 2)
	{
		return (float)otherPresVotes / (float)voterCapacity;
	}
	else if (num == 3)
	{
		return (float)democratSenVotes / (float)voterCapacity;
	}
	else if (num == 4)
	{
		return (float)republicanSenVotes / (float)voterCapacity;
	}
	else if (num == 5)
	{
		return (float)otherSenVotes / (float)voterCapacity;
	}
}

//float States::getPerDemPres()
//{
//	return percentDemPres;
//}
//
//float States::getPerRepPres()
//{
//	return percentRepPres;
//}
//
//float States::getPerOtherPres()
//{
//	return percentOtherPres;
//}
//
//float States::getPerDemSen()
//{
//	return percentDemSen;
//}
//
//float States::getPerRepSen()
//{
//	return percentRepSen;
//}
//
//float States::getPerOtherSen()
//{
//	return percentOtherSen;
//}
//
//void States::setPerDemPres(float f)
//{
//	percentDemPres = f;
//}
//
//void States::setPerRepPres(float f)
//{
//	percentRepPres = f;
//}
//
//void States::setPerOtherPres(float f)
//{
//	percentOtherPres = f;
//}
//
//void States::setPerDemSen(float f)
//{
//	percentDemSen = f;
//}
//
//void States::setPerRepSen(float f)
//{
//	percentRepSen = f;
//}
//
//void States::setPerOtherSen(float f)
//{
//	percentOtherSen = f;
//}




