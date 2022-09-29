#include "StoringData.h"

void StoringData::updateTimeMapIns(double t) {
	//keeps only the largest value of insertion time
	if (t > timeMapIns) {
		timeMapIns = t;
	}
}
void StoringData::updateTimeTreeIns(double t) {
	//keeps only the largest value of insertion time
	if (t > timeTreeIns) {
		timeTreeIns = t;
	}
}