#include <iostream>
#include <string>
#include <vector>
#include "States.h"
#include "Districts.h"
using namespace std;


int main()
{
    States createStates;
    createStates.readCSV("District_map.csv", 0);
    auto iter = createStates.stateMap.begin();
    for (iter; iter != createStates.stateMap.end(); iter++) {
        *iter->second.
    }
    
}




