#include "TimeMeasure.h"

TimeMeasure::TimeMeasure()
{
    stateMapTree = DataHandler::stateTree;
    stateMapMap = DataHandler::stateMap;
}

void TimeMeasure::compareStructures()
{
    string states[50] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware",
        "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana",
       "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska",
       "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio",
       "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah",
       "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" };

	cout << "Comparing the times to search and traverse for the AVL tree and unordered_map\n" << endl;

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

    cout << "Ratio of Search time of AVL tree to unordered_map: " << fixed << setprecision(2) << time_taken / time_taken_two  << "\n\n" << endl;

    updateTimeTreeInsert(DataHandler::st.timeTreeIns);
    updateTimeMapInsert(DataHandler::st.timeMapIns);
    setTimeTreeTraversal(DataHandler::st.timeTreeTravers);
    setTimeMapTraversal(DataHandler::st.timeMapTravers);

    cout << "Time taken to insert a state by AVL Tree: " << fixed << setprecision(9) << timeTreeInsert ;
    cout << "sec\n" << endl;

    cout << "Time taken to insert a state by unordered_map: " << fixed << setprecision(9) << timeMapInsert ;
    cout << "sec\n" << endl;

    cout << "Ratio of Insertion time of AVL tree to unordered_map: " << fixed << setprecision(2) << timeTreeInsert / timeMapInsert  << "\n\n" << endl;

    cout << setprecision(9);
    cout << "Time taken to traverse the AVL Tree: " << fixed << setprecision(9) << timeTreeTraversal ;
    cout << "sec\n" << endl;

    cout << "Time taken to traverse the unordered_map: " << fixed << setprecision(9) << timeMapTraversal ;
    cout << "sec\n" << endl;

    cout << "Ratio of Traversal time of AVL tree to unordered_map: " << fixed << setprecision(2) << timeTreeTraversal / timeMapTraversal  << "\n\n" << endl;
}

void TimeMeasure::updateTimeTreeInsert(double t)
{
    timeTreeInsert = t;
}

void TimeMeasure::updateTimeMapInsert(double t)
{
     timeMapInsert = t;
}

void TimeMeasure::setTimeTreeTraversal(double t)
{
    timeTreeTraversal = t;
}

void TimeMeasure::setTimeMapTraversal(double t)
{
    timeMapTraversal = t;
}

double TimeMeasure::getTimeTreeInsert()
{
    return timeTreeInsert;
}

double TimeMeasure::getTimeMapInsert()
{
    return timeMapInsert;
}

double TimeMeasure::getTimeTreeTraversal()
{
    return timeTreeTraversal;
}

double TimeMeasure::getTimeMapTraversal()
{
    return timeMapTraversal;
}
