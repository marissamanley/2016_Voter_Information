#include "DataHandler.h"

unordered_map<string, States> DataHandler::stateMap;


/*
 * Reads the District_map CSV file to form the stateMap and DistrictMap structures
 * Reads in voter information for each district in each state
 * offset brings you to the state that you want to visit.
 * Ex: Offset = 0 brings you to first state, Alabama
 * States are in alphabetical order in csv
 */
void DataHandler::readCSV(string filePath, int offset) {
	ifstream file(filePath);
	string lineFromFile;

	//Offset plus skipping first two rows
	for (int i = 0; i < offset + 2; i++) {
		getline(file, lineFromFile);
	}

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
		

		for (int i = 1; i < numDistricts+1; i++) {
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
			state.districtMap.emplace(i, district);
		}
		
		stateMap.emplace(stateName, state);
	}
}

void DataHandler::initData() {
	readCSV("District_map.csv");
}