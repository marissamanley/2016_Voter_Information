#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "States.h"
#include "Districts.h"
#include "Voter.h"
using namespace std;

void printStates();
void printStatesTwo(unordered_map<string, States> s);
void createVoters();
void createVotersTwo(unordered_map<string, States>& s);
void readCSVTwo(string filePath, int offset, unordered_map<string, States> &s);

/*
 * TODO:
 *  - Fill out CSV for every state
 *  - Create Splay tree to pass in voters
 *  - Calculate winners for each candidate
 *  - Calculate electoral college wins
 *  - User interface to display data
 *  - Search to display data
 * 
 * Potentially?
 *  Make this project more dynamic and modular:
 *  - Allow user to increase/decrease voter turnout at the nation, state, or district level
 *  - Allow user to increase/decrease voter turnout for a specific party at the nation, state, or district level
 *      - lets users see how turnout can affect the electoral college
 *      - would set caps for max turnout at each district
 */
int main()
{
    unordered_map<string, States> statesTwo;
    readCSVTwo("District_map.csv", 0, statesTwo);
    printStatesTwo(statesTwo);
    //printStates();
    //createVoters();
}

/*
 * All state and district information are obtained in the CSV master file
 * The values in the CSV are based off the results of the 2020 election
 * All information is gathered from here: http://www.electproject.org/2020g
 */
void printStates() 
{
    States createStates;
    createStates.readCSV("District_map.csv");
    auto iter = createStates.stateMap.begin();
    for (iter; iter != createStates.stateMap.end(); iter++) {
        string state = iter->second.getState();
        cout << "State: " << state << endl;
        cout << "Democrat Senator: " << iter->second.getDemSenator() << endl;
        cout << "Republican Senator: " << iter->second.getRepSenator() << endl;
        cout << "Number of voters: " << iter->second.getVoterCapacity() << endl;
        cout << "Number of electoral votes: " << iter->second.getElectoralVotes() << endl << endl;

        for (int i = 0; i < iter->second.getNumDistricts(); i++) {
            auto& curDistrict = createStates.districtMap[state][i];
            cout << "District Number: " << curDistrict.getDistrict() << endl;
            cout << "Number of voters: " << curDistrict.getVoterCapacity() << endl;
            cout << "Democrat Representative: " << curDistrict.getDemocrat() << endl;
            cout << "Republican Representative: " << curDistrict.getRepublican() << endl;
            cout << "Dem Percentage: " << curDistrict.getPercentDem() * 100 << "%" << endl;
            cout << "Rep Percentage: " << curDistrict.getPercentRep() * 100 << "%" << endl;
            cout << "Third Party Percentage: " << curDistrict.getPercentOther() * 100 << "%" << endl << endl;
        }
    }
}

void printStatesTwo(unordered_map<string, States> s)
{
    auto iter = s.begin();
    for (iter; iter != s.end(); iter++) {
        cout << "State: " << iter->first << endl;
        cout << "Democrat Senator: " << iter->second.getDemSenator() << endl;
        cout << "Republican Senator: " << iter->second.getRepSenator() << endl;
        cout << "Number of voters: " << iter->second.getVoterCapacity() << endl;
        cout << "Number of electoral votes: " << iter->second.getElectoralVotes() << endl << endl;

        for (auto it = iter->second.districtMapTwo.begin(); it != iter->second.districtMapTwo.end(); it++)
        {
            cout << "District Number: " << it->second.getDistrict() << endl;
            cout << "Number of voters: " << it->second.getVoterCapacity() << endl;
            cout << "Democrat Representative: " << it->second.getDemocrat() << endl;
            cout << "Republican Representative: " << it->second.getRepublican() << endl;
            cout << "Dem Percentage: " << it->second.getPercentDem() * 100 << "%" << endl;
            cout << "Rep Percentage: " << it->second.getPercentRep() * 100 << "%" << endl;
            cout << "Third Party Percentage: " << it->second.getPercentOther() * 100 << "%" << endl << endl;
        }
    }
}

/*
 * Generates random voters
 * Starts at first state, then first district within that state
 * Generates voters based on percent dem, rep, other
 * Push vote to splay tree
 *
 * Question: Do we want the potential for voters to not vote for all races? (presidential, Senate, House)
 *           Do we want the potential for voters to not vote down party line?
 */
void createVoters() {
    States createStates;
    createStates.readCSV("District_map.csv");
    int demCount = 0;
    int repCount = 0;
    int otherCount = 0;
    auto iter = createStates.stateMap.begin();
    //loops through every state
    for (iter; iter != createStates.stateMap.end(); iter++) {
        //loops through every district within that state
        for (int district = 0; district < iter->second.getNumDistricts(); district++) {
            auto curDistrict = createStates.districtMap[iter->second.getState()][district];
            //loops through the number of voters within that district
            for (int voter = 0; voter < curDistrict.getVoterCapacity(); voter++) {
                //generates what party the voter is voting for
                Voter::party castVote = Voter::vote(curDistrict.getPercentDem(), curDistrict.getPercentRep(), curDistrict.getPercentOther());
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
        }
    }
    cout << "Dem Count: " << demCount << endl;
    cout << "Rep Count: " << repCount << endl;
    cout << "Third Party Count: " << otherCount << endl;
}

void createVotersTwo(unordered_map<string, States>& s)
{
}

void readCSVTwo(string filePath, int offset, unordered_map<string, States> &s) {
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
            state.districtMapTwo.emplace(districtNumber, district);
        }
        s.emplace(stateName, state);
    }
}




