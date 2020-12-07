#include "main.h"
#include <iostream>
#include <string>
#include <vector>
#include "States.h"
#include "Districts.h"
#include "Voter.h"
#include "DataHandler.h"
#include "TreeNode.h"
#include "Tree.h"
#include "TimeMeasure.h"
using namespace std;


int* nationalInfoMap(unordered_map<string, States>& sMap);
void senatorialInfoAVL(TreeNode* root);
void nationalInfoAVL(TreeNode* root, int* info);

int main()
{
    DataHandler::initData();
    unordered_map<string, States>& sMap = DataHandler::stateMap;
    Tree* sTree = DataHandler::stateTree;
    TimeMeasure meas = TimeMeasure();
    string presidentDem = "Joe Biden";
    string presidentRep = "Donald Trump";

    string states[50] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware",
         "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana",
        "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska",
        "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio",
        "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah",
        "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" };
    int sortInput = -1;

    while (sortInput != 0) {
        cout << "Welcome to the 539 Election Data Search!" << endl;
        cout << "\nPlease input one of the following to select the method by which the data will be accessed:" << endl;
        cout << "[0] Exit 539 Election Data Search" << endl;
        cout << "[1] Unordered Map" << endl;
        cout << "[2] AVL Tree" << endl;
        cout << "[3] Time Comparison\n" << endl;


        cout << "Selection: ";
        cin >> sortInput;

        if (sortInput == 0)
        {
            cout << "Thank you for using 539 Election Data Search!" << endl;
            return 0;
        }

        int input = 1;
        if (sortInput == 3)
        {
            meas.compareStructures();
            input = 0;
        }
        
        while (input != 0)
        {
            cout << "Please input one of the folowing to select the National Election Data, all Senatorial data, or a specific state:" << endl;
            cout << "[0] Return to Data Access Method Selection" << endl;
            cout << "[51] National Election Data " << endl;
            cout << "[52] All Senatorial Election Data\n" << endl;

            cout << "    [1] Alabama     | [11] Hawaii   | [21] Massachusetts | [31] New Mexico     | [41] South Dakota\n\
    [2] Alaska      | [12] Idaho    | [22] Michigan      | [32] New York       | [42] Tennessee\n\
    [3] Arizona     | [13] Illinois | [23] Minnesota     | [33] North Carolina | [43] Texas\n\
    [4] Arkansas    | [14] Indiana  | [24] Mississippi   | [34] North Dakota   | [44] Utah\n\
    [5] California  | [15] Iowa     | [25] Missouri      | [35] Ohio           | [45] Vermont\n\
    [6] Colorado    | [16] Kansas   | [26] Montana       | [36] Oklahoma       | [46] Virginia\n\
    [7] Connecticut | [17] Kentucky | [27] Nebraska      | [37] Oregon         | [47] Washington\n\
    [8] Deleware    | [18] Loisiana | [28] Nevada        | [38] Pennsylvania   | [48] West Virginia\n\
    [9] Florida     | [19] Maine    | [29] New Hampshire | [39] Rhode Island   | [49] Wisconsin\n\
    [10] Georgia    | [20] Maryland | [30] New Jersey    | [40] South Carolina | [50] Wyoming\n\n";
            cout << "Selection: ";
            cin >> input;
            if (input == 51)
            {
                if (sortInput == 1)
                {
                    cout << "National Election Data:" << endl;
                    int* info = nationalInfoMap(sMap);
                    printf("Candidate Name: Joe Biden                 | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: %d", info[0], ((double)info[0]) / info[3], DataHandler::demElectoralVotes());
                    printf("Candidate Name: Donald Trump              | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: %d", info[1], ((double)info[1]) / info[3], DataHandler::repElectoralVotes());
                    printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: 0", info[2], ((double)info[2]) / info[3]);
                    cout << endl;
                }
                else
                {
                    int info[3];
                    nationalInfoAVL(sTree->root, info);
                    int total = info[0] + info[1] + info[2];
                    cout << "National Election Data:" << endl;
                    printf("Candidate Name: Joe Biden                 | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: %d", info[0], ((double)info[0]) / total, DataHandler::demElectoralVotes());
                    printf("Candidate Name: Donald Trump              | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: %d", info[1], ((double)info[1]) / total, DataHandler::repElectoralVotes());
                    printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: 0", info[2], ((double)info[2]) / total);
                    cout << endl;
                }
            }
            else if (input == 52)
            {
                if (sortInput == 1)
                {
                    auto start = chrono::high_resolution_clock::now();
                    for (auto j = sMap.begin(); j != sMap.end(); j++)
                    {
                        if (j->second.getDemSenator().compare("NONE") != 0 && j->second.getRepSenator().compare("NONE") != 0)
                        {
                            cout << "\nSenatorial Election Data for " << j->second.getState() << ": " << endl;
                            printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", j->second.getDemSenator().c_str(), j->second.getDemSenVotes(), j->second.getPercent(3));
                            printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", j->second.getRepSenator().c_str(), j->second.getRepSenVotes(), j->second.getPercent(4));
                            printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", j->second.getOtherSenVotes(), j->second.getPercent(5));
                        }
                        else
                        {
                            cout << "\nNo Senatorial Election Data available for " << j->second.getState() << "." << endl;
                        }
                    }
                    auto end = chrono::high_resolution_clock::now();

                    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    
                    DataHandler::st.timeMapTravers = time_taken;
                }
                else if (sortInput == 2)
                {
                    auto start = chrono::high_resolution_clock::now();
                    senatorialInfoAVL(sTree->root);
                    auto end = chrono::high_resolution_clock::now();

                    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    DataHandler::st.timeTreeTravers = time_taken;
                }
            }
            else if(input >= 1 && input <= 50)
            {
                int selectedState = input - 1;
                States state;
                TreeNode* stateNode;
                if (sortInput == 1)
                    state = sMap[states[selectedState]];
                else
                {
                    stateNode = sTree->search(sTree->root, states[selectedState]);
                    state = stateNode->state;
                }

                cout << "State: " << state.getState() << endl;
                cout << "Number of voters: " << state.getVoterCapacity() << endl;
                cout << "Number of electoral votes: " << state.getElectoralVotes() << endl;

                int input2 = -1;
                while (input2 != 0) {
                    cout << "\nPlease input one of the following to select the data for the state " << state.getState() << ":" << endl;
                    cout << "[0] Return to State selection" << endl;
                    cout << "[1] National Election data" << endl;
                    cout << "[2] Senatorial Election Data" << endl;
                    cout << "[3] ALL District Election Data" << endl;
                    cout << "[4] A Single District's Election Data\n" << endl;
                    cout << "Selection: ";

                    cin >> input2;
                    if (input2 == 1)
                    {
                        cout << "National Election Data for " << state.getState() << ": " << endl;
                        printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", presidentDem.c_str(), state.getDemPresVotes(), state.getPercent(0));
                        printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", presidentRep.c_str(), state.getRepPresVotes(), state.getPercent(1));
                        printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", state.getOtherPresVotes(), state.getPercent(2));
                    }

                    else if (input2 == 2)
                    {
                        if (state.getDemSenator().compare("NONE") != 0 && state.getRepSenator().compare("NONE") != 0)
                        {
                            cout << "Senatorial Election Data for " << state.getState() << ": " << endl;
                            printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", state.getDemSenator().c_str(), state.getDemSenVotes(), state.getPercent(3));
                            printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", state.getRepSenator().c_str(), state.getRepSenVotes(), state.getPercent(4));
                            printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", state.getOtherSenVotes(), state.getPercent(5));
                        }
                        else
                        {
                            cout << "No Senatorial Election Data available for " << state.getState() << "." << endl;
                        }
                    }

                    else if (input2 == 3)
                    {
                        state.districtInfo();
                    }

                    else if (input2 == 4)
                    {
                        int distInput = 1;
                        cout << "There are " << state.getNumDistricts() << " congressional districts in the state of " << state.getState() << ". Input number for a district. Press 0 to exit District search:" << endl;
                        cout << "Selection: ";
                        cin >> distInput;
                        Districts district = state.districtMap[distInput];
                        cout << "\nRepresentative Election Data for district " << distInput << " in " << state.getState() << ": " << endl;
                        printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", district.getDemocrat().c_str(), district.getVotersDem(), district.getPercent(6));
                        printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", district.getRepublican().c_str(), district.getVotersRep(), district.getPercent(7));
                        printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", district.getVotersOther(), district.getPercent(8));
                    }
                }
            }
        }
    }
}

    




int* nationalInfoMap(unordered_map<string, States>& sMap)
{
    int demVotes = 0;
    int repVotes = 0;
    int othVotes = 0;
    int total = 0;
    int info[4];
    for (auto i = sMap.begin(); i != sMap.end(); i++)
    {
        demVotes += i->second.getDemPresVotes();
        repVotes += i->second.getRepPresVotes();
        othVotes += i->second.getOtherPresVotes();
        total += i->second.getVoterCapacity();
    }
    info[0] = demVotes;
    info[1] = repVotes;
    info[2] = othVotes;
    info[3] = total;

    return info;

}

void nationalInfoAVL(TreeNode* root, int* info)
{
	if (root == nullptr)
		return;

	nationalInfoAVL(root->left, info);

	info[0] += root->state.getDemPresVotes();
    info[1] += root->state.getRepPresVotes();
    info[2] += root->state.getOtherPresVotes();

	nationalInfoAVL(root->right, info);
}

void senatorialInfoAVL(TreeNode* root)
{
    if (root == nullptr)
        return;

    senatorialInfoAVL(root->left);

    cout << "\nSenatorial Election Data for " << root->state.getState() << ": " << endl;
    printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", root->state.getDemSenator().c_str(), root->state.getDemSenVotes(), root->state.getPercent(3));
    printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", root->state.getRepSenator().c_str(), root->state.getRepSenVotes(), root->state.getPercent(4));
    printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", root->state.getOtherSenVotes(), root->state.getPercent(5));

    senatorialInfoAVL(root->right);
}

