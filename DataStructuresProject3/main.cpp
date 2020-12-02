#include "main.h"
#include <iostream>
#include <string>
#include <vector>
#include "States.h"
#include "Districts.h"
#include "Voter.h"
#include "DataHandler.h"
using namespace std;

int main()
{

    unordered_map<string, States>& sMap = DataHandler::stateMap;

    //This is gonna be sorted!! oho??
    string states[50] = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", 
         "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", 
        "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", 
        "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", 
        "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", 
        "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
        

    cout << "Welcome. Please input the number for a state, or enter 51 for National Election Data. Press 0 to exit program:\n" << endl;
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
            /*States state = sMap[states[input]];
            cout << "State: " << state.getState() << endl;
            cout << "Democrat Senator: " << state.getDemSenator() << endl;
            cout << "Republican Senator: " << state.getRepSenator() << endl;
            cout << "Number of voters: " << state.getVoterCapacity() << endl;
            cout << "Number of electoral votes: " << state.getElectoralVotes() << endl << endl;
            */
            
            //cout << "Please input 0 for the National Election data, 1 for the Senatorial Election Data, or 2 to select a District within " << state.getState() << endl;
            int input2;
            cin >> input2;
            if (input2 == 0)
            {
                //National election data based on the state: Name % NumVotes, repeat
            }

            if (input2 == 1)
            {
                //Sentate election based on the state
            }
            
            if (input2 == 2)
            {
                int distInput = 1;
                //cout << "There are " << state.getNumDistricts() << " congressional districts in the state of " << state.getState() << ". Input number for a district. Press 0 to exit district search:";
                while (distInput != 0)
                {
                    cin >> distInput;
                    /*Districts district = state.districtMap[--distInput];
                    cout << "District Number: " << district.getDistrict() << endl;
                    cout << "Number of voters: " << district.getVoterCapacity() << endl;
                    
                    //Ask for input regarding National, Senate, or District data based on this district
                        cout << "Democrat Representative: " << district.getDemocrat() << endl;
                        cout << "Republican Representative: " << district.getRepublican() << endl;
                        cout << "Dem Percentage: " << district.getPercentDem() * 100 << "%" << endl;
                        cout << "Rep Percentage: " << district.getPercentRep() * 100 << "%" << endl;
                        cout << "Third Party Percentage: " << district.getPercentOther() * 100 << "%" << endl << endl;
                        */
                    cout << "Input number for a district. Press 0 to exit district search:";
                }
            }
        }


        cout << "\nPlease input the number for a state, or enter 51 for National Election Data. Press 0 to exit program:\n" << endl;
    }
    cout << "Thank you for using 539! Or something snarky idk" << endl;
}


