#include <iostream>
#include <string>
#include <vector>
#include "States.h"
#include "Districts.h"
using namespace std;

void printStates();

int main()
{
    printStates();
}

void printStates() 
{
    States createStates;
    createStates.readCSV("District_map.csv", 0);
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



