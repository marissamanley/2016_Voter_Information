#include "States.h"

map<int, States> States::stateMap;
map<string, vector<Districts>> States::districtMap;

States::States() {};

States::States(string state, int voterCapacity, int numDistricts, string demSenator, string repSenator, int electoralVotes) {
	this->state = state;
	this->voterCapacity = voterCapacity;
	this->numDistricts = numDistricts;
	this->demSenator = demSenator;
	this->repSenator = repSenator;
	this->electoralVotes = electoralVotes;
}


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

/*
 * Reads in voter information for each district in each state
 * offset brings you to the state that you want to visit.
 * Ex: Offset = 0 brings you to first state, Alabama
 * States are in alphabetical order in csv
 */
void States::readCSV(string filePath, int offset) {
	ifstream file(filePath);
	string lineFromFile;

	//Offset plus skipping first two rows
	for (int i = 0; i < offset + 2; i++) {
		getline(file, lineFromFile);
	}

	int stateIndex = 0;
	while (getline(file, lineFromFile)) {
		istringstream streamFromAString(lineFromFile);

		string stateName;
		getline(streamFromAString, stateName, ',');
		
		string demRep;
		getline(streamFromAString, demRep, ',');

		string repRep;
		getline(streamFromAString, repRep, ',');

		string voters;
		getline(streamFromAString, voters, ',');
		int numVoters = stoi(voters);

		string electoralVotes_;
		getline(streamFromAString, electoralVotes_, ',');
		int electoralVotes = stoi(electoralVotes_);

		string numDistrics_;
		getline(streamFromAString, numDistrics_, ',');
		int numDistricts = stoi(numDistrics_);

		States state(stateName, numVoters, numDistricts, demRep, repRep, electoralVotes);
		stateMap.emplace(stateIndex, state);

		vector<Districts> districts;
		for (int i = 0; i < numDistricts; i++) {
			string districtNumber_;
			getline(streamFromAString, districtNumber_, ',');
			int districtNumber = stoi(districtNumber_);

			getline(streamFromAString, voters, ',');
			numVoters = stoi(voters);

			getline(streamFromAString, demRep, ',');
			getline(streamFromAString, repRep, ',');
			
			string percentDem;
			getline(streamFromAString, percentDem, ',');
			float perDem = stof(percentDem);

			string percentRep;
			getline(streamFromAString, percentRep, ',');
			float perRep = stof(percentRep);

			Districts district(districtNumber, numVoters, perDem, perRep, demRep, repRep);
			districts.push_back(district);
		}
		districtMap.emplace(stateName, districts);
		stateIndex++;
	}
}



