#include "Districts.h"

// Constructor that takes in parameters from the CSV
Districts::Districts(int district, int voterCapacity, float percentDem, float percentRep, std::string democratRep, std::string republicanRep) {
	this->district = district;
	this->voterCapacity = voterCapacity;
	this->initPercentDem = percentDem;
	this->initPercentRep = percentRep;
	this->democrat = democratRep;
	this->republican = republicanRep;
	this->initPercentOther = 1 - (percentDem + percentRep);
}

// Many setter and getter functions for district information
int Districts::getDistrict() {
	return this->district;
}

void Districts::setDistrict(int district) {
	this->district = district;
}

int Districts::getVoterCapacity() {
	return this->voterCapacity;
}

void Districts::setVoterCapacity(int voterCapacity) {
	this->voterCapacity = voterCapacity;
}

int Districts::getVotersDem() {
	return this->votersDem;
}

void Districts::setVotersDem(int v) {
	this->votersDem = v;
}

int Districts::getVotersRep() {
	return this->votersRep;
}

void Districts::setVotersRep(int v) {
	this->votersRep = v;
}

int Districts::getVotersOther() {
	return this->votersOther;
}

void Districts::setVotersOther(int v) {
	this->votersOther = v;
}

int Districts::getVotersSenDem() {
	return votersSenDem;
}

void Districts::setVotersSenDem(int v) {
	votersSenDem = v;
}

int Districts::getVotersSenRep() {
	return votersSenRep;
}

void Districts::setVotersSenRep(int v) {
	votersSenRep = v;
}

int Districts::getVotersSenOther() {
	return votersSenOther;
}

void Districts::setVotersSenOther(int v) {
	votersSenOther = v;
}

int Districts::getVotersPresDem() {
	return votersPresDem;
}

void Districts::setVotersPresDem(int v) {
	votersPresDem = v;
}

int Districts::getVotersPresRep() {
	return votersPresRep;
}

void Districts::setVotersPresRep(int v) {
	votersPresRep = v;
}

int Districts::getVotersPresOther() {
	return votersPresOther;
}

void Districts::setVotersPresOther(int v) {
	votersPresOther = v;
}

// These methods add the voter count for their respective party
void Districts::addVotersDem(int voterCount) {
	setVotersDem(voterCount);
	setVotersPresDem(voterCount);
	setVotersSenDem(voterCount);
}

void Districts::addVotersRep(int voterCount) {
	setVotersRep(voterCount);
	setVotersPresRep(voterCount);
	setVotersSenRep(voterCount);
}

void Districts::addVotersOther(int voterCount) {
	setVotersOther(voterCount);
	setVotersPresOther(voterCount);
	setVotersSenOther(voterCount);
}

// Initial percentages is taken from the csv, used to generate voters
float Districts::getInitPercentDem() {
	return initPercentDem;
}

void Districts::setInitPercentDem(float percentDem) {
	initPercentDem = percentDem;
}

float Districts::getInitPercentRep() {
	return initPercentRep;
}

void Districts::setInitPercentRep(float percentRep) {
	initPercentRep = percentRep;
}

float Districts::getInitPercentOther() {
	return initPercentOther;
}

void Districts::setInitPercentOther(float percentOther) {
	initPercentOther = percentOther;
}

std::string Districts::getDemocrat() {
	return this->democrat;
}

void Districts::setDemocrat(std::string dem) {
	democrat = dem;
}

std::string Districts::getRepublican() {
	return this->republican;
}

void Districts::setRepublican(std::string rep) {
	republican = rep;
}

// Gets percentages for each office; used for the main menu
float Districts::getPercent(int num)
{
	if (num == 0) {
		return 100 * (float)votersPresDem / (float)voterCapacity;
	}
	else if (num == 1) {
		return 100 * (float)votersPresRep / (float)voterCapacity;
	}
	else if (num == 2) {
		return 100 * (float)votersPresOther / (float)voterCapacity;
	}
	else if (num == 3) {
		return 100 * (float)votersSenDem / (float)voterCapacity;
	}
	else if (num == 4) {
		return 100 * (float)votersSenRep / (float)voterCapacity;
	}
	else if (num == 5) {
		return 100 * (float)votersSenOther / (float)voterCapacity;
	}
	else if (num == 6) {
		return 100 * (float)votersDem / (float)voterCapacity;
	}
	else if (num == 7) {
		return 100 * (float)votersRep / (float)voterCapacity;
	}
	else if (num == 8) {
		return 100 * (float)votersOther / (float)voterCapacity;
	}
}
