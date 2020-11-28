#include "Districts.h"

Districts::Districts(int district, int voterCapacity, float percentDem, float percentRep, float percentOther) {
	this->district = district;
	this->voterCapacity = voterCapacity;
	this->percentDem = percentDem;
	this->percentRep = percentRep;
	this->percentOther = percentOther;
}