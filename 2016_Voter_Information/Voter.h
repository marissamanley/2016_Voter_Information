#pragma once
#include "Random.h"

/*
 * This class generates what party the voter casts their vote to based on the party represenation of the district
 */

class Voter {
public:
	enum party {DEM, REP, THIRD};
	Voter() {};

	/*
	 * This functions generates what party a single voter casts their vote to
	 * The percentages input are initial percentages from the CSV
	 * The voter representation at the district and state level will differ from the actual data, but will be very similar
	 * Returns an enumeration of which party the voter casts their vote to
	 */
	static party vote(float percentDem, float percentRep, float percentThird) {
		float castVote = Random::Float(0, 1.0f);
		if (castVote <= percentDem)
			return Voter::party::DEM;
		else if (castVote <= percentDem+percentRep)
			return Voter::party::REP;
		else
			return Voter::party::THIRD;
	}
};

