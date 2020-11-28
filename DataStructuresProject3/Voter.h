#pragma once
#include "Random.h"

/*
 * This class generates what party the voter casts their vote to based on the party represenation of the district
 */

class Voter
{
public:
	enum party {DEM, REP, THIRD};
	Voter() {};

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

