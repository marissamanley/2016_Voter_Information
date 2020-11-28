#pragma once
#include "Random.h"
class Voter
{
public:
	enum party {DEM, REP, THIRD};
	Voter() {};

	//
	static party vote(float percentDem, float percentRep, float percentThird) {
		float castVote = Random::Float(0, 1.0f);
		if (castVote <= percentThird)
			return Voter::party::THIRD;
		else if (castVote > percentThird && castVote <= percentRep)
			return Voter::party::REP;
		else
			return Voter::party::DEM;
	}
};

