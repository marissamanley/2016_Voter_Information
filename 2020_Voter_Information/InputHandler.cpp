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
#include "InputHandler.h"

//Begins the program by outputting the welcome messages and processing the initial user input
void InputHandler::Start() {
    while (sortInput != 0) { //Continues the program until user inputs 0 to exit data search
        std::cout << "Welcome to the 539 Election Data Search!" << std::endl;
        std::cout << "\nPlease input one of the following to select the method by which the data will be accessed:" << std::endl;
        std::cout << "[0] Exit 539 Election Data Search" << std::endl;
        std::cout << "[1] Unordered Map" << std::endl;
        std::cout << "[2] AVL Tree" << std::endl;
        std::cout << "[3] Time Comparison\n" << std::endl;
        std::cout << "Selection: ";
        std::cin >> sortInput;

        if (sortInput == 0) { //Ends program 
            std::cout << "Thank you for using 539 Election Data Search!" << std::endl;
            return;
        }
        else if (sortInput == 1 || sortInput == 2) {
            dataAccess();
        }
        else if (sortInput == 3) {
            meas.compareStructures();
        }
        else {
            std::cout << "Invalid entry. Try again.\n" << std::endl;
        }
    }
}

//Iterates through the unordered map of states to acquire National Election data
void InputHandler::nationalInfoMap() {
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "National Election Data:" << std::endl;
    int demVotes = 0, repVotes = 0, othVotes = 0, total = 0;
    for (auto i = DataHandler::stateMap.begin(); i != DataHandler::stateMap.end(); i++) {
        demVotes += i->second.getDemPresVotes();
        repVotes += i->second.getRepPresVotes();
        othVotes += i->second.getOtherPresVotes();
    }
    total = demVotes + repVotes + othVotes;
    printf("Candidate Name: Joe Biden                 | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: %d\n", demVotes, ((double)demVotes / total) * 100, DataHandler::demElectors+3);
    printf("Candidate Name: Donald Trump              | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: %d\n", repVotes, ((double)repVotes / total) * 100, DataHandler::repElectors);
    printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: 0\n\n", othVotes, ((double)othVotes / total) * 100);
}

//Iterates through the AVL Tree of states to acquire National Election data
void InputHandler::nationalInfoTree() {
    int info[3] = { 0 };
    DataHandler::stateTree->nationalInfoAVL(DataHandler::stateTree->root, info);
    int total = info[0] + info[1] + info[2];
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "National Election Data:" << std::endl;
    printf("Candidate Name: Joe Biden                 | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: %d\n", info[0], ((double)info[0] / total) * 100, DataHandler::demElectors+3);
    printf("Candidate Name: Donald Trump              | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: %d\n", info[1], ((double)info[1] / total) * 100, DataHandler::repElectors);
    printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% | Electoral Votes: 0\n", info[2], ((double)info[2] / total) * 100);
    std::cout << std::endl;
}

//Outputs all Senatorial Data from either the AVL Tree or unordered map
void InputHandler::nationalSenatorialData() {
    if (sortInput == 1) {//Accesses data through the unordered map
        for (auto j = DataHandler::stateMap.begin(); j != DataHandler::stateMap.end(); j++) {
            if (j->second.getDemSenator().compare("NONE") != 0 && j->second.getRepSenator().compare("NONE") != 0) {
                std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "\nSenatorial Election Data for " << j->second.getState() << ": " << std::endl;
                printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", j->second.getDemSenator().c_str(), j->second.getDemSenVotes(), j->second.getPercent(3));
                printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", j->second.getRepSenator().c_str(), j->second.getRepSenVotes(), j->second.getPercent(4));
                printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", j->second.getOtherSenVotes(), j->second.getPercent(5));
            }
            else {
                std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "\nNo Senatorial Election Data available for " << j->second.getState() << "." << std::endl;
            }
        }
    }
    else {//Accessed data through the AVL tree 
        DataHandler::stateTree->senatorialInfoAVL(DataHandler::stateTree->root, true); 
    }
}

// Retrieves the correct State information based on the used input
void InputHandler::stateSelect(int input) {
    int selectedState = input - 1;
    States state;
    TreeNode* stateNode;
    if (sortInput == 1) //Map
        state = DataHandler::stateMap[meas.states[selectedState]]; 
    else { //Tree
        stateNode = DataHandler::stateTree->search(DataHandler::stateTree->root, meas.states[selectedState]);
        state = stateNode->state; 
    }
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "State: " << state.getState() << std::endl;
    std::cout << "Number of voters: " << state.getVoterCapacity() << std::endl;
    std::cout << "Number of electoral votes: " << state.getElectoralVotes() << std::endl;

    int input2 = -1;
    while (input2 != 0) { //Loops through State Data selection until user inputs to return to State selection
        std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "\nPlease input one of the following to select the data for the state " << state.getState() << ":" << std::endl;
        std::cout << "[0] Return to State selection" << std::endl;
        std::cout << "[1] National Election data" << std::endl;
        std::cout << "[2] Senatorial Election Data" << std::endl;
        std::cout << "[3] ALL District Election Data" << std::endl;
        std::cout << "[4] A Single District's Election Data\n" << std::endl;
        std::cout << "Selection: ";

        std::cin >> input2;
        if (input2 == 1) { //Outputs National Election data based on the selected state 
            std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "National Election Data for " << state.getState() << ": " << std::endl;
            printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", presidentDem.c_str(), state.getDemPresVotes(), state.getPercent(0));
            printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", presidentRep.c_str(), state.getRepPresVotes(), state.getPercent(1));
            printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", state.getOtherPresVotes(), state.getPercent(2));
        }
        else if (input2 == 2) {//Outputs Senatorial Election data based on the selected state 
            if (state.getDemSenator().compare("NONE") != 0 && state.getRepSenator().compare("NONE") != 0) {
                std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "Senatorial Election Data for " << state.getState() << ": " << std::endl;
                printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", state.getDemSenator().c_str(), state.getDemSenVotes(), state.getPercent(3));
                printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", state.getRepSenator().c_str(), state.getRepSenVotes(), state.getPercent(4));
                printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", state.getOtherSenVotes(), state.getPercent(5));
            }
            else {
                std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "No Senatorial Election Data available for " << state.getState() << "." << std::endl;
            }
        }
        else if (input2 == 3) {//Outputs all District Election data based on the selected state
            state.districtInfo();
        }
        else if (input2 == 4) {//Allows for user to select specific District data based on the selected state
            int distInput = 0;
            while (distInput < 1 || distInput > state.getNumDistricts()) {
                std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "There are " << state.getNumDistricts() << " congressional districts in the state of " << state.getState() << ". Input number for a district. Press 0 to exit District search:" << std::endl;
                std::cout << "Selection: ";
                std::cin >> distInput;
                if (distInput > 0 && distInput < state.getNumDistricts() + 1) {
                    Districts district = state.districtMap[distInput];
                    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
                    std::cout << "\nRepresentative Election Data for district " << distInput << " in " << state.getState() << ": " << std::endl;
                    printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", district.getDemocrat().c_str(), district.getVotersDem(), district.getPercent(6));
                    printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", district.getRepublican().c_str(), district.getVotersRep(), district.getPercent(7));
                    printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", district.getVotersOther(), district.getPercent(8));
                }
            }
        }
    }
}

// Retrieves data based on user input
void InputHandler::dataAccess() {
    int input = 1;
    while (input != 0) { 
        std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "\nPlease input one of the folowing to select the National Election Data, all Senatorial data, or a specific state:" << std::endl;
        std::cout << "[0] Return to Data Access Method Selection" << std::endl;
        std::cout << "[51] National Election Data " << std::endl;
        std::cout << "[52] All Senatorial Election Data\n" << std::endl;

        std::cout << "        [1] Alabama     | [11] Hawaii   | [21] Massachusetts | [31] New Mexico     | [41] South Dakota\n\
        [2] Alaska      | [12] Idaho    | [22] Michigan      | [32] New York       | [42] Tennessee\n\
        [3] Arizona     | [13] Illinois | [23] Minnesota     | [33] North Carolina | [43] Texas\n\
        [4] Arkansas    | [14] Indiana  | [24] Mississippi   | [34] North Dakota   | [44] Utah\n\
        [5] California  | [15] Iowa     | [25] Missouri      | [35] Ohio           | [45] Vermont\n\
        [6] Colorado    | [16] Kansas   | [26] Montana       | [36] Oklahoma       | [46] Virginia\n\
        [7] Connecticut | [17] Kentucky | [27] Nebraska      | [37] Oregon         | [47] Washington\n\
        [8] Deleware    | [18] Loisiana | [28] Nevada        | [38] Pennsylvania   | [48] West Virginia\n\
        [9] Florida     | [19] Maine    | [29] New Hampshire | [39] Rhode Island   | [49] Wisconsin\n\
        [10] Georgia    | [20] Maryland | [30] New Jersey    | [40] South Carolina | [50] Wyoming\n\n";
        std::cout << "Selection: ";
        std::cin >> input;

        if (input == 51) { //National Election Data
            if (sortInput == 1) { //unordered map
                nationalInfoMap();
            }
            else { //AVL tree
                nationalInfoTree();
            }
        }
        else if (input == 52) {//All Senatorial Data
            nationalSenatorialData();
        }
        else if (input >= 1 && input <= 50) {//Selected state 
            stateSelect(input);
        }
    }
}