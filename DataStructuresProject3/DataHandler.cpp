#include "DataHandler.h"

unordered_map<string, States> DataHandler::stateMap;
Tree* DataHandler::stateTree = new Tree();
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
		DataHandler::stateTree->root = DataHandler::stateTree->insert(DataHandler::stateTree->root, &state);

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


void DataHandler::createVoters() {
	int demCount = 0;
	int repCount = 0;
	int otherCount = 0;
	auto iter = DataHandler::stateMap.begin();
	//loops through every state
	for (iter; iter != DataHandler::stateMap.end(); iter++) {
		//loops through every district within that state
		auto& curState = iter->second;
		for (int i = 1; i < iter->second.getNumDistricts() + 1; i++) {
			auto& curDistrict = iter->second.districtMap[i];
			//loops through the number of voters within that district
			for (int voter = 0; voter < curDistrict.getVoterCapacity(); voter++) {
				//generates what party the voter is voting for
				Voter::party castVote = Voter::vote(curDistrict.getInitPercentDem(), curDistrict.getInitPercentRep(), curDistrict.getInitPercentOther());
				//Insert into Splay tree here
				switch (castVote)
				{
				case Voter::DEM:
					demCount++;
					break;
				case Voter::REP:
					repCount++;
					break;
				case Voter::THIRD:
					otherCount++;
					break;
				default:
					break;
				}
			}
			curState.addDemVotes(demCount, i);
			curState.addRepVotes(repCount, i);
			curState.addOtherVotes(otherCount, i);
			//curDistrict.setVotersDem(demCount);
			//curDistrict.setVotersRep(repCount);
			//curDistrict.setVotersOther(otherCount);
		}
	}
}

void DataHandler::initData() {
	readCSV("District_map.csv");
	createVoters();
}