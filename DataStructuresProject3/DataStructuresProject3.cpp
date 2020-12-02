#include "main.h"
#include <iostream>
#include <string>
#include <vector>
#include "States.h"
#include "Districts.h"
#include "Voter.h"
#include "DataHandler.h"
using namespace std;

void createVoters();

int main()
{
    DataHandler::initData();
    unordered_map<string, States>& sMap = DataHandler::stateMap;
    createVoters();
    string presidentDem;
    string presidentRep;

    //This is gonna be sorted!! oho??
    string states[50] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware",
         "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana",
        "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska",
        "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio",
        "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah",
        "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" };


    cout << "Welcome!" << endl;
    cout << "Please input the number for a state, or enter 51 for National Election Data. Press 0 to exit program : \n" << endl;
    cout << "[1] Alabama     | [11] Hawaii   | [21] Massachusetts | [31] New Mexico     | [41] South Dakota\n\
    [2] Alaska      | [12] Idaho    | [22] Michigan      | [32] New York       | [42] Tennessee\n\
    [3] Arizona     | [13] Illinois | [23] Minnesota     | [33] North Carolina | [43] Texas\n\
    [4] Arkansas    | [14] Indiana  | [24] Mississippi   | [34] North Dakota   | [44] Utah\n\
    [5] California  | [15] Iowa     | [25] Missouri      | [35] Ohio           | [45] Vermont\n\
    [6] Colorado    | [16] Kansas   | [26] Montana       | [36] Oklahoma       | [46] Virginia\n\
    [7] Connecticut | [17] Kentucky | [27] Nebraska      | [37] Oregon         | [47] Washington\n\
    [8] Deleware    | [18] Loisiana | [28] Nevada        | [38] Pennsylvania   | [48] West Virginia\n\
    [9] Florida     | [19] Maine    | [29] New Hampshire | [39] Rhode Island   | [49] Wisconsin\n\
    [10] Georgia    | [20] Maryland | [30] New Jersey    | [40] South Carolina | [50] Wyoming\n\n";


    int input = 1;
    while (input != 0)
    {
        cin >> input;
        input--;
        if (input == 51)
        {
            cout << "NATIONAL ELECTION:" << endl;
            //Iterate through every national candidate
            cout << "Candidate Name: Xxxxx Xxxx | Vote Count: 0000 | Vote Percentage: 00%" << endl;
            cout << endl;
        }
        else
        {
            States state = sMap[states[input]];
            cout << "State: " << state.getState() << endl;
            cout << "Democrat Senator: " << state.getDemSenator() << endl;
            cout << "Republican Senator: " << state.getRepSenator() << endl;
            cout << "Number of voters: " << state.getVoterCapacity() << endl;
            cout << "Number of electoral votes: " << state.getElectoralVotes() << endl << endl;


            cout << "Please input 0 for the National Election data, 1 for the Senatorial Election Data, or 2 to select a District within " << state.getState() << endl;
            int input2;
            cin >> input2;
            if (input2 == 0)
            {
                cout << "National Election Data: " << endl;
                cout << "Candidate Name: Xxxxx Xxxx | Vote Count: " << state.getDemPresVotes() << "   | Vote Percentage: " << state.getPercent(0) << "%" << endl;
                cout << "Candidate Name: Xxxxx Xxxx | Vote Count: " << state.getRepPresVotes() << "   | Vote Percentage: " << state.getPercent(1) << "%" << endl;
                cout << "Candidate Name: Other      | Vote Count: " << state.getOtherPresVotes() << " | Vote Percentage: " << state.getPercent(2) << "%" << endl;
                //National election data based on the state: Name % NumVotes, repeat
            }

            if (input2 == 1)
            {
                cout << "Senatorial Election Data: " << endl;
                cout << "Candidate Name: " << state.getDemSenator() << " | Vote Count: " << state.getDemSenVotes() << "   | Vote Percentage: " << state.getPercent(3) << "%" << endl;
                cout << "Candidate Name: " << state.getRepSenator() << " | Vote Count: " << state.getRepSenVotes() << "   | Vote Percentage: " << state.getPercent(4) << "%" << endl;
                cout << "Candidate Name: Other      | Vote Count: " << state.getOtherSenVotes() << " | Vote Percentage: " << state.getPercent(5) << "%" << endl;
            }

            if (input2 == 2)
            {
                int distInput = 1;
                cout << "There are " << state.getNumDistricts() << " congressional districts in the state of " << state.getState() << ". Input number for a district. Press 0 to exit district search:";
                while (distInput != 0)
                {
                    cin >> distInput;
                    Districts district = state.districtMap[--distInput];
                    cout << "District Number: " << district.getDistrict() << endl;
                    cout << "Number of voters: " << district.getVoterCapacity() << endl;

                    int dataInput = 1;
                    cout << "Enter a 1 to see National data, 2 to see Senatorial Data, or 3 to see District Data. Press 0 to exit District Data search" << endl;
                    while (dataInput != 0)
                    {
                        cin >> dataInput;
                        if (dataInput == 1)
                        {
                            cout << "National Election Data: " << endl;
                            cout << "Candidate Name: Xxxxx Xxxx | Vote Count: " << district.getVotersPresDem() << "   | Vote Percentage: " << district.getPercent(0) << "%" << endl;
                            cout << "Candidate Name: Xxxxx Xxxx | Vote Count: " << district.getVotersPresRep() << "   | Vote Percentage: " << district.getPercent(1) << "%" << endl;
                            cout << "Candidate Name: Other      | Vote Count: " << district.getVotersPresOther() << " | Vote Percentage: " << district.getPercent(2) << "%" << endl;
                        }
                        if (dataInput == 2)
                        {
                            cout << "Senatorial Election Data: " << endl;
                            cout << "Candidate Name: " << state.getDemSenator() << " | Vote Count: " << district.getVotersSenDem() << "   | Vote Percentage: " << district.getPercent(3) << "%" << endl;
                            cout << "Candidate Name: " << state.getRepSenator() << " | Vote Count: " << district.getVotersSenRep() << "   | Vote Percentage: " << district.getPercent(4) << "%" << endl;
                            cout << "Candidate Name: Other      | Vote Count: " << district.getVotersSenOther() << " | Vote Percentage: " << district.getPercent(5) << "%" << endl;
                        }
                        if (dataInput == 3)
                        {
                            cout << "Representative Election Data: " << endl;
                            cout << "Candidate Name: " << district.getDemocrat() << " | Vote Count: " << district.getVotersDem() << "   | Vote Percentage: " << district.getPercent(6) << "%" << endl;
                            cout << "Candidate Name: " << district.getRepublican() << " | Vote Count: " << district.getVotersRep() << "   | Vote Percentage: " << district.getPercent(7) << "%" << endl;
                            cout << "Candidate Name: Other      | Vote Count: " << district.getVotersOther() << " | Vote Percentage: " << district.getPercent(8) << "%" << endl;
                        }
                        cout << "Enter a 1 to see National data, 2 to see Senatorial Data, or 3 to see District Data. Press 0 to exit District Data search" << endl;
                    }

                    cout << "Input number for a district. Press 0 to exit District search:";
                }
            }
        }


        cout << "\nPlease input the number for a state, or enter 51 for National Election Data. Press 0 to exit program:\n" << endl;
    }
    cout << "Thank you for using 539! Or something snarky idk" << endl;


    return 0;
}

void createVoters() {
    int demCount = 0;
    int repCount = 0;
    int otherCount = 0;
    auto iter = DataHandler::stateMap.begin();
    //loops through every state
    for (iter; iter != DataHandler::stateMap.end(); iter++) {
        //loops through every district within that state
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
        }
    }
    //cout << "Dem Count: " << demCount << endl;
    //cout << "Rep Count: " << repCount << endl;
    //cout << "Third Party Count: " << otherCount << endl;
}
/*#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "States.h"
#include "Districts.h"
#include "Voter.h"
#include "DataHandler.h"
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

//int main()
//{
//    DataHandler::initData();
//    printStates();
//    createVoters();
//
//    return 0;
//}

/*
 * All state and district information are obtained in the CSV master file
 * The values in the CSV are based off the results of the 2020 election
 * All information is gathered from here: http://www.electproject.org/2020g
 */

/*void printStates()
{
    auto iter = DataHandler::stateMap.begin();
    for (iter; iter != DataHandler::stateMap.end(); iter++) {
        string state = iter->second.getState();
        cout << fixed << setprecision(1);
        cout << "State: " << state << endl;
        cout << "Democrat Senator: " << iter->second.getDemSenator() << endl;
        cout << "Republican Senator: " << iter->second.getRepSenator() << endl;
        cout << "Number of voters: " << iter->second.getVoterCapacity() << endl;
        cout << "Number of electoral votes: " << iter->second.getElectoralVotes() << endl << endl;

        for (int i = 1; i < iter->second.getNumDistricts()+1; i++) {
            auto& curDistrict = iter->second.districtMap[i];
            cout << "District Number: " << curDistrict.getDistrict() << endl;
            cout << "Number of voters: " << curDistrict.getVoterCapacity() << endl;
            cout << "Democrat Representative: " << curDistrict.getDemocrat() << endl;
            cout << "Republican Representative: " << curDistrict.getRepublican() << endl;
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

/*void createVoters() {
    int demCount = 0;
    int repCount = 0;
    int otherCount = 0;
    auto iter = DataHandler::stateMap.begin();
    //loops through every state
    for (iter; iter != DataHandler::stateMap.end(); iter++) {
        //loops through every district within that state
        for (int i = 1; i < iter->second.getNumDistricts()+1; i++) {
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
        }
    }
    cout << "Dem Count: " << demCount << endl;
    cout << "Rep Count: " << repCount << endl;
    cout << "Third Party Count: " << otherCount << endl;
}

*/


