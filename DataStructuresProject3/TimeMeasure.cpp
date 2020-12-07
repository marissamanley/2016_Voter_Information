#include "TimeMeasure.h"

//default constructor
TimeMeasure::TimeMeasure()
{
    stateMapTree = DataHandler::stateTree;
    stateMapMap = DataHandler::stateMap;
}

//the main function that outputs the comparison
void TimeMeasure::compareStructures()
{
    string states[50] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware",
        "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana",
       "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska",
       "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio",
       "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah",
       "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" };

	cout << "Comparing the times to search and traverse for the AVL tree and unordered_map\n" << endl;

    // the search comparison section. uses a random statename as input
    int num = rand() % 50 + 1;

    string statename = states[num];
	auto start = chrono::high_resolution_clock::now();

    TreeNode* r = stateMapTree->search(stateMapTree->root, statename);

	auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Time taken to search for state by AVL Tree: " << fixed << setprecision(9) << time_taken ;
    cout << "sec\n" << endl;

    start = chrono::high_resolution_clock::now();

    States state = stateMapMap[statename];

    end = chrono::high_resolution_clock::now();

    double time_taken_two = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken_two *= 1e-9;

    
    cout << "Time taken to search for state by unordered_map: " << fixed << setprecision(9) << time_taken_two ;
    cout << "sec\n" << endl;

    //Outputs a ratio of AVL tree to unordered_map for easier comparison
    cout << "Ratio of Search time of AVL tree to unordered_map: " << fixed << setprecision(2) << time_taken / time_taken_two  << "\n\n" << endl;

    //gets values from StoringData object for the insertion and traversal operations
    updateTimeTreeInsert(DataHandler::st.timeTreeIns);
    updateTimeMapInsert(DataHandler::st.timeMapIns);
    setTimeTreeTraversal(DataHandler::st.timeTreeTravers);
    setTimeMapTraversal(DataHandler::st.timeMapTravers);

    //outputs the times taken for insertion for each structure
    cout << "Time taken to insert a state by AVL Tree: " << fixed << setprecision(9) << timeTreeInsert ;
    cout << "sec\n" << endl;

    cout << "Time taken to insert a state by unordered_map: " << fixed << setprecision(9) << timeMapInsert ;
    cout << "sec\n" << endl;

    cout << "Ratio of Insertion time of AVL tree to unordered_map: " << fixed << setprecision(2) << timeTreeInsert / timeMapInsert  << "\n\n" << endl;

    //outputs the times taken for traversal for each structure
    cout << setprecision(9);
    cout << "Time taken to traverse the AVL Tree: " << fixed << setprecision(9) << timeTreeTraversal ;
    cout << "sec\n" << endl;

    cout << "Time taken to traverse the unordered_map: " << fixed << setprecision(9) << timeMapTraversal ;
    cout << "sec\n" << endl;

    cout << "Ratio of Traversal time of AVL tree to unordered_map: " << fixed << setprecision(2) << timeTreeTraversal / timeMapTraversal  << "\n\n" << endl;
}

//updates the tree insertion time
void TimeMeasure::updateTimeTreeInsert(double t)
{
    timeTreeInsert = t;
}

//updates the map insertion time
void TimeMeasure::updateTimeMapInsert(double t)
{
     timeMapInsert = t;
}

//updates the tree traversal time
void TimeMeasure::setTimeTreeTraversal(double t)
{
    timeTreeTraversal = t;
}

//updates the map traversal time
void TimeMeasure::setTimeMapTraversal(double t)
{
    timeMapTraversal = t;
}

//get the tree insertion time
double TimeMeasure::getTimeTreeInsert()
{
    return timeTreeInsert;
}

//get the map insertion time
double TimeMeasure::getTimeMapInsert()
{
    return timeMapInsert;
}

//get the tree traversal time
double TimeMeasure::getTimeTreeTraversal()
{
    return timeTreeTraversal;
}

//get the map traversal time
double TimeMeasure::getTimeMapTraversal()
{
    return timeMapTraversal;
}
