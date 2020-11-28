#include "Districts.h"

Districts::Districts(int district, int voterCapacity, float percentDem, float percentRep, string democratRep, string republicanRep) {
	this->district = district;
	this->voterCapacity = voterCapacity;
	this->percentDem = percentDem;
	this->percentRep = percentRep;
	this->democrat = democratRep;
	this->republican = republicanRep;
	this->percentOther = 1 - (percentDem + percentRep);
}

int Districts::getDistrict() {
	return this->district;
}

int Districts::getVoterCapacity() {
	return this->voterCapacity;
}

float Districts::getPercentDem() {
	return this->percentDem;
}

float Districts::getPercentRep() {
	return this->percentRep;
}

string Districts::getDemocrat() {
	return this->democrat;
}

string Districts::getRepublican() {
	return this->republican;
}
