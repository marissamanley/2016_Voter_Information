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

	cout << "Comparing the times to search and traverse for the AVL tree and unordered_map" << endl;

    int num = rand() % 50 + 1;

    string statename = states[num];
	auto start = chrono::high_resolution_clock::now();

    TreeNode* r = stateMapTree->search(stateMapTree->root, statename);

	auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Time taken to search for state by AVL Tree: " << fixed << time_taken << setprecision(9);
    cout << "sec\n" << endl;

    start = chrono::high_resolution_clock::now();

    States state = stateMapMap[statename];

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Time taken to search for state by unordered_map: " << fixed << time_taken << setprecision(9);
    cout << "sec\n" << endl;

    cout << "Time taken to insert a state by AVL Tree: " << fixed << timeTreeInsert << setprecision(9);
    cout << "sec\n" << endl;

    cout << "Time taken to insert a state by unordered_map: " << fixed << timeMapInsert << setprecision(9);
    cout << "sec\n" << endl;

    cout << "Time taken to traverse the AVL Tree: " << fixed << timeTreeTraversal << setprecision(9);
    cout << "sec\n" << endl;

    cout << "Time taken to traverse the unordered_map: " << fixed << timeMapTraversal << setprecision(9);
    cout << "sec\n" << endl;
}

void TimeMeasure::updateTimeTreeInsert(double t)
{
    if (t > timeTreeInsert)
    {
        timeTreeInsert = t;
    }
}

void TimeMeasure::updateTimeMapInsert(double t)
{
    if (t > timeMapInsert)
    {
        timeMapInsert = t;
    }
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
