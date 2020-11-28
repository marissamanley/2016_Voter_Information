#include <iostream>
#include <string>
#include <vector>
#include "States.h"
#include "Districts.h"
#include "Voter.h"
using namespace std;

void printStates();
void createVoters();


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
    printStates();
    createVoters();
}

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
    for (iter; iter != createStates.stateMap.end(); iter++) {
        for (int district = 0; district < iter->second.getNumDistricts(); district++) {
            auto curDistrict = createStates.districtMap[iter->second.getState()][district];
            for (int voter = 0; voter < curDistrict.getVoterCapacity(); voter++) {
                Voter::party castVote = Voter::vote(curDistrict.getPercentDem(), curDistrict.getPercentRep(), curDistrict.getPercentOther());
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



