# 2016_Voter_Information

## Team Name
M^4EI
## Team Members
Marissa Manley, Marcus Elosegui, Mark Itkin

Link to Video: https://youtu.be/yeZA8jq4Hks

# Proposal
## Problem
Over the past decade there have been discussions over whether online elections are
feasible and whether they could replace physical elections. Such a system would require a
strong defense against attacks, while also having a reliable and convenient vote counting
process. How a vote counting and result displaying system could be implemented is the
problem we seek to solve.

## Motivation
If online elections become more of a possibility, it will be important to understand
some possible solutions for storing voter data and producing election results. We want to
provide a preliminary implementation for this part of the online voting process. This sets up an
initial step from which a more involved and fully-fledged structure can be built.
Features Implemented: The program allows the user to access all generated national,
senatorial, and representative election data from the 2020 election. The user can select whether
to access the data from the AVL Tree or the Unordered Map, or to complete a Time
Comparison. Then, the user can select whether to see the national election data on the national
level, select to see the senatorial election data for all 50 U.S. states, or input a number
associated with each of the 50 U.S. states. If a state is selected, the user can select whether to
see the national election data on the state level, the senatorial election data for that state, all the
representative election data for that state, or they can select to choose one of the district’s
within the state and see the representative election data for that district. The program also
allows the user to return to previous menus to access other data.

## Description of data
The data we used is randomly generated voter data based on election
results from the 2020 election. The percentages of votes for each district candidate were logged
in a .csv file for each state. Once the file was read, the program randomly generates voters
based on the percentages and logs the vote in voter counts for Democrat candidates,
Republican candidates, and other candidates. In addition, the total amount of votes generated
for each category is limited by a scaled value of votes. This allows for a smaller sample size,
bringing the total amount of votes nationally from around 160 million to about 160 thousand.
Tools/Languages/APIs/Libraries used: We used C++ as our language to create this software,
and we used the standard library available for C++ for much of our functions on Visual Studio
2017/2019.

## Data Structures/Algorithms implemented
We implemented an AVL tree with the capability to
insert, remove, and search. The tree was also self-balancing, checking for a well balanced tree
after each insertion or removal. To allow for easier access to data from the AVL tree, we also
implemented multiple Inorder Traversals to get national and senatorial data.
Data Structures/Algorithms used: In order to have a structure to compare the AVL tree to, we
used an Unordered_Map from the C++ standard library. Since the Unordered_Map is
implemented in the library as a Hashmap, it allows us to get a comparison of performance of an
AVL Tree to a Hashmap.

## Distribution of Responsibility and Roles
Marcus Elosegui's main tasks revolved around implementing the code that would create the
initial states and districts and generate the voters, as well as filling out the .csv file used. He
created and filled out the majority of the .csv that holds scaled voter values, senate and house
candidates, and the percentages of votes for each candidate. Marcus also created the function
that reads the .csv and stores the data to the AVL Tree and Unordered Map. The other function
he implemented is the one that creates all of the voters and adds the total counts to the districts
and states.
Marissa Manley's main tasks revolved around implementing the code that would access data
from the AVL tree and Unordered Map and produce the results in an organized and
easy-to-read format. In our main function, she created a menu that would allow for access to
election results pulled from either the AVL Tree or the Unordered Map. As part of the menu,
Marissa implemented functions that would traverse the AVL Tree and Unordered Map to obtain
total national results and all senatorial results. She also helped complete the .csv file used for
creating the initial states and districts.
Mark Itkin's main tasks revolved around implementing classes that facilitated the AVL tree
structure as well as comparing the performance of both structures used in the project. He
created much of the functions in the States and Districts classes, including the get/set functions
and the percentage calculating functions. Mark also created the Tree and TreeNode classes,
making sure that they worked with the states and their respective districts. The other classes he
implemented were the TimeMeasure class and the StoringData class, which are used in tandem
to get performance times of the two structures.

## Changes
Since the initial group proposal, the changes to the overall project have been
minimal, as our ideas for the theme issues and project features remained the same. Our data
structures were switched from an Unordered Map and a Splay Tree to an Unordered Map and
an AVL Tree. This was because we decided that a self-balancing AVL Tree was a more
appropriate Data Structure to use for our specific program, which involved accessing State
nodes using the string name of the state, and would not necessarily need the most recently
accessed element. Additionally, we solidified the specifics regarding available output options
and means of accessing the available data on the menu, which included offering National
election data at both the national and state data, showing all the Senatorial Data at a national
level, and showing all the District data at the state level.


## Complexity Analysis
*traversal of Unordered Map to get all senatorial results*
Worst case: O(S), where S is the number of U.S. states
This method traverses the Unordered Map to access all senatorial results
*insertion of state into Unordered Map*
Worst case: O(1)
This method inserts a state into the Unordered Map
*void nationalInfoMap(unordered_map<string, States>& sMap, int* info)*
Worst case: O(S), where S is the number of U.S. States
This method traverses the unordered map of states to access the national data from each state
*void senatorialInfoAVL(TreeNode* root)*
Worst case: O(S) where S is the number of U.S. States
This method traverses the AVL tree of states to access the senatorial data from each state
*void nationalInfoAVL(TreeNode* root, int* info)*
Worst case: O(S) where S is the number of U.S. States
This method traverses the AVL tree of states to access the national data from each state
*void DataHandler::createVoters()*
Worst case: O(S * D * V), where S is the number of U.S. States, D is the number of
Districts in a given State, and V is the number of votes in a given District
This method iterates through the total number of voters in very district in every state to generate
the votes to be inserted in either the AVL tree or the Unordered Map
*void DataHandler::initData()*
Worst case: O(1)
This method calls the readCSV() function, the createVoters(function), and the
calculateElectoralVotes() function
*void DataHandler::calculateElectoralVotes()*
Worst case: O(S), where S is the number of U.S. States
This method traverses the unordered map of states to gather all the state electoral vote data
*void DataHandler::readCSV(string filePath, int offset)*
Worst case: O( (S * D) +O) , where S is the number of U.S. States, D is the number of
Districts in a given state, and O is the value for the offset, which is the number of lines
that need to be ignored while reading the .csv file
*void States::districtInfo()*
Worst case: O(D), where D is the number of Districts in a given State
This method iterates through all the districts in a state and outputs the relevant district data
*TreeNode* Tree::search(TreeNode* root, string statename)*
Worst case: O(log(S)), where S is the number of U.S. States
This method searches the AVL tree using the state name and returns the state TreeNode*
*TreeNode* Tree::insert(TreeNode* root, States *s)*
Worst case: O(log(S)), where S is the number of U.S. States
This method inserts a state TreeNode* into the AVL tree and calls methods to balance the tree
*int Tree::height(TreeNode* root)*
Worst case: O(S), where S is the number of U.S. States
This method returns the height of the TreeNode* in the parameter
*int Tree::balanceValue(TreeNode* root)*
Worst case: O(1)
This method returns the number of the balance value, which is used to determine if the tree
needs to be balanced based on the recent insertion/deletion
*TreeNode* Tree::leftRotate(TreeNode* root)*
Worst case: O(1)
This method rotates the AVL tree left at the given root TreeNode*
*TreeNode* Tree::rightRotate(TreeNode* root)*
Worst case: O(1)
This method rotates the AVL tree right at the given root TreeNode*
*TreeNode* Tree::leftRightRotate(TreeNode* root)*
Worst case: O(1)
This method rotates the AVL tree left and then right at the given root TreeNode*
*TreeNode* Tree::rightLeftRotate(TreeNode* root)*
Worst case: O(1)
This method rotates the AVL tree right and then left at the given root TreeNode*
*void TimeMeasure::compareStructures()*
Worst case: O(1)
This method calls the unordered map and AVL tree search functions and outputs the time
elapsed for each, and then also outputs the time elapsed for the insertion and traversal
operations for each structure. In addition, it does a quick ratio calculation for each type of
operation.

## Performance Comparison of AVL Tree and Unordered Map
Reviewing the worst case complexities of insertion for each of the structures, it can be seen that the AVL
Tree performs at a slower rate than the Unordered Map, taking O(log S) time compared to O(1). A similar
situation can be seen for the search operations, with the AVL tree taking O(log S) time to find a state
versus O(1) time for the Unordered Map. This difference is due to the structure of the Unordered Map,
which is modeled with a Hashmap. This allows the Unordered Map to have multiple positions at which the
state can be placed at, and only taking more time when there are collisions in the insertion process. While
this difference is evident for the search and insertion operations, the traversal operations perform
similarly, with both structures taking O(S) time to travel through their values. This is simply due to the
inherent necessity of a traversal to pass every value.
These comparisons of complexity are further displayed in the code itself, with the option to obtain
runtimes for these operations as well as ratios of AVL Tree time to Unordered Map time. When run, the
ratio for the search operation is some amount greater than 1 (meaning a slower runtime for the AVL tree),
while the ratio for traversal operations is around 1 (meaning similar times of traversal). While the insertion
ratio should also be some amount greater than 1, the ratio sometimes ends up being closer to 1 due to
the program choosing the longest times for each structure, which in turn means it is considering the cases
where the Unordered Map has collisions in the insertion process.

# Reflection
## Experience
The project experience overall was educational and interesting. For some group
members, this project harbored the introduction to collaborating with other programmers on a
single program, as well pushing, pulling and committing code through GitHub repositories,
which is an especially relevant skill to have with regard to Computer Science as a profession.
Furthermore, the project allowed for additional practice of different Data Structures/Algorithms
and encouraged a “learning by doing” means of understanding lesser known programming
concepts.

## Challenges
The main challenge that was faced, although a minor one, stemmed from project
coordination rather than the programming itself. Though each member was on time and never
was delayed when committing their code, there were brief points when the productivity of one
member was paused because a second member was still working on their part, but such is an
inevitable byproduct of collaborating on a single program. Otherwise, Compiler and Runtime
Errors were encountered, but they were amended as soon as they arose. It was also the first
time all of us got an opportunity to really get familiar with github, so it took some time for us to
get set up and figure out how to utilize github correctly.

## Changes if redone
If we were to start this project again, we would try to use a dataset that
is already in existence, rather than generate random voters. An example of this could be using
data from the 2016 election instead of the 2020 election. We would also implement options for
multiple senators in addition to candidates from third-parties. If time allowed, we could
implement a GUI that allows for users to select the state from an image rather than just from
menu options. One other possible change is to create more detailed voter profiles to match a
more realistic point of data at the beginning of the counting process. This would include their
votes from each of the races that they voted in, and store voters individually. Ideally, we would
also like to include the possibility of having multiple senate races in a state, like in Georgia
currently. We could also take into account states that split up their electoral college votes, like
Maine, to make it more representative of real life.

## What we learned
We learned about how to correctly use github, as it was all of our first times
utilizing the platform in such a formal group collaborative manner. In using github, we also got
an opportunity to learn about how we can efficiently work within a group on a program, getting
familiar with the process of working with other people and integrating each person's code
together. Outside of github, our team members also learned about how to use the time
measuring functions from std::chrono.

## References:
Associated Press, via Google
https://www.ap.org/media-center/understanding-the-election
https://www.google.com/search?q=2020+election+results&oq=2020+el&aqs=chrome.0.0i433i45
7j69i57j0i433l3j69i60l3.1975j0j7&sourceid=chrome&ie=UTF-8
United States Election Project
http://www.electproject.org/2020g
