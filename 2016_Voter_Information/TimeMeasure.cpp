#include "TimeMeasure.h"

//the main function that outputs the comparison
void TimeMeasure::compareStructures(){
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Comparing the times to search, insert, and traverse the AVL tree and unordered_map:\n" << std::endl;

    // the search comparison section. uses a random statename as input
    int num = rand() % 50 + 1;
    std::string statename = states[num];

	auto start = std::chrono::high_resolution_clock::now();
    TreeNode* r = DataHandler::stateTree->search(DataHandler::stateTree->root, statename);
	auto end = std::chrono::high_resolution_clock::now();
    double time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

    start = std::chrono::high_resolution_clock::now();
    States state = DataHandler::stateMap[statename];
    end = std::chrono::high_resolution_clock::now();
    double time_taken_two = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;
    
    std::cout << "Time taken to search for state by AVL Tree: " << std::fixed << std::setprecision(9) << time_taken << " sec" << std::endl;;
    std::cout << "Time taken to search for state by unordered_map: " << std::fixed << std::setprecision(9) << time_taken_two << " sec" << std::endl;
    std::cout << "Ratio of Search time of AVL tree to unordered_map: " << std::fixed << std::setprecision(2) << time_taken / time_taken_two  << "\n\n" << std::endl;

    //outputs the times taken for insertion for each structure
    std::cout << "Time taken to insert a state by AVL Tree: " << std::fixed << std::setprecision(9) << DataHandler::st.timeTreeIns << " sec" << std::endl; ;
    std::cout << "Time taken to insert a state by unordered_map: " << std::fixed << std::setprecision(9) << DataHandler::st.timeMapIns << " sec" << std::endl;;
    std::cout << "Ratio of Insertion time of AVL tree to unordered_map: " << std::fixed << std::setprecision(2) << DataHandler::st.timeTreeIns / DataHandler::st.timeMapIns << "\n\n" << std::endl;

    //outputs the times taken for traversal for each structure
    start = std::chrono::high_resolution_clock::now();
    for (auto j = DataHandler::stateMap.begin(); j != DataHandler::stateMap.end(); j++) {}
    end = std::chrono::high_resolution_clock::now();
    timeMapTraversal = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) *1e-9;
                    
    start = std::chrono::high_resolution_clock::now();
    DataHandler::stateTree->senatorialInfoAVL(DataHandler::stateTree->root, false);
    end = std::chrono::high_resolution_clock::now();
    timeTreeTraversal = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;
    
    std::cout << std::setprecision(9);
    std::cout << "Time taken to traverse the AVL Tree: " << std::fixed << std::setprecision(9) << timeTreeTraversal << " sec" << std::endl;
    std::cout << "Time taken to traverse the unordered_map: " << std::fixed << std::setprecision(9) << timeMapTraversal << " sec" << std::endl;
    std::cout << "Ratio of Traversal time of AVL tree to unordered_map: " << std::fixed << std::setprecision(2) << timeTreeTraversal / timeMapTraversal  << "\n" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;

}
