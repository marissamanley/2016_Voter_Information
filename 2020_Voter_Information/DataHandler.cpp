#include "DataHandler.h"
#include <unordered_map>

std::unordered_map<std::string, States> DataHandler::stateMap;
Tree* DataHandler::stateTree = new Tree();
StoringData DataHandler::st;
int DataHandler::demElectors;
int DataHandler::repElectors;
/*
 * Reads the District_map CSV file to form the stateMap and DistrictMap structures
 * Information order: state name, names of senators, electoral college voters, number of voters,
 * number of districts, distict candidates, party representation of that district.
 */
void DataHandler::readCSV(std::string filePath, int offset) {
	std::ifstream file(filePath);
	std::string lineFromFile;
	// Automatically skips the first two rows of the .csv
	for (int i = 0; i < offset + 2; i++) {
		getline(file, lineFromFile);
	}
	while (getline(file, lineFromFile)) {
		std::istringstream streamFromAString(lineFromFile);

		std::string stateName, demRep, repRep, voters, electoralVotes_, numDistrics_;
		std::getline(streamFromAString, stateName, ',');

		std::getline(streamFromAString, demRep, ',');
		std::getline(streamFromAString, repRep, ',');
		std::getline(streamFromAString, voters, ',');
		int numVoters = stoi(voters);
		std::getline(streamFromAString, electoralVotes_, ',');
		int electoralVotes = stoi(electoralVotes_);
		std::getline(streamFromAString, numDistrics_, ',');
		int numDistricts = stoi(numDistrics_);

		States state(stateName, numVoters, numDistricts, demRep, repRep, electoralVotes);
		
		for (int i = 1; i < numDistricts+1; i++) {
			std::string districtNumber_;
			std::getline(streamFromAString, districtNumber_, ',');
			int districtNumber = stoi(districtNumber_);

			std::getline(streamFromAString, voters, ',');
			numVoters = stoi(voters);

			std::getline(streamFromAString, demRep, ',');
			std::getline(streamFromAString, repRep, ',');

			std::string percentDem;
			std::getline(streamFromAString, percentDem, ',');
			float perDem = stof(percentDem);

			std::string percentRep;
			std::getline(streamFromAString, percentRep, ',');
			float perRep = stof(percentRep);

			Districts district(districtNumber, numVoters, perDem, perRep, demRep, repRep);
			state.districtMap[i] = district;
		}

		//Used for time comparisons between AVL and unordered_map insertions
		//AVL Tree
		auto start = std::chrono::high_resolution_clock::now();
		DataHandler::stateTree->root = DataHandler::stateTree->insert(DataHandler::stateTree->root, &state);
		auto end = std::chrono::high_resolution_clock::now();

		double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		DataHandler::st.updateTimeTreeIns(time_taken);

		//Unordered_map
		start = std::chrono::high_resolution_clock::now();
		stateMap[stateName] = state;
		end = std::chrono::high_resolution_clock::now();

		time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		DataHandler::st.updateTimeMapIns(time_taken);
	}
}

/*
 * This function loops through every state and every district within that state.
 * It calls upon the voter class to generate a every voter based on party percentages within that district.
 * The addvote methods are then called upon to store this voting data within each state.
 */
void DataHandler::createVoters() {
	auto iter = DataHandler::stateMap.begin();
	//loops through every state
	int treeCount = 0;
	for (iter; iter != DataHandler::stateMap.end(); iter++) {
		//loops through every district within that state
		auto& curState = iter->second;
		TreeNode* curTreeState = stateTree->search(stateTree->root, curState.getState());
		for (int i = 1; i < iter->second.getNumDistricts() + 1; i++) {
			auto& curDistrict = iter->second.districtMap[i];
			int demCount = 0, repCount = 0, otherCount = 0;
			//loops through the number of voters within that district
			for (int voter = 0; voter < curDistrict.getVoterCapacity(); voter++) {
				//generates voter party
				Voter::party castVote = Voter::vote(curDistrict.getInitPercentDem(), curDistrict.getInitPercentRep(), curDistrict.getInitPercentOther());
				switch (castVote) {
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
			// Adds the votes to the state object after every district. Done for both AVL state and map state
			curTreeState->state.addDemVotes(demCount, i);
			curTreeState->state.addRepVotes(repCount, i);
			curTreeState->state.addOtherVotes(otherCount, i);
			curState.addDemVotes(demCount, i);
			curState.addRepVotes(repCount, i);
			curState.addOtherVotes(otherCount, i);
		}
	}
}

/*
 * This method calculates the amount of electoral votes assigned to each candidate by looping
 * through the state and retrieving which candidate won the popular vote
 * Note: third party candidates are not considered and states with split votes are not taken into account
 */
void DataHandler::calculateElectoralVotes() {
	auto iter = DataHandler::stateMap.begin();
	demElectors = 0;
	repElectors = 0;
	for (iter; iter != DataHandler::stateMap.end(); iter++) {
		auto& curState = iter->second;
		Voter::party winner = curState.determineWinner();
		switch (winner) {
		case Voter::DEM:
			demElectors += curState.getElectoralVotes();
			break;
		case Voter::REP:
			repElectors += curState.getElectoralVotes();
			break;
		default:
			break;
		}
	}
}

// This calls upon these methods to initialize all data used for the menu
void DataHandler::initData() {
	readCSV("District_map.csv");
	createVoters();
	calculateElectoralVotes();
}
