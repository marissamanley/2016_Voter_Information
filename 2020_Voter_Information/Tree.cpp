#include "Tree.h"
//Default constructor
Tree::Tree() {
	root = nullptr;
}

//function to compare statenames
int Tree::compareStateNames(std::string one, std::string two) {
	if (one.compare(two) < 0) {
		return -1;
	}
	else if (one.compare(two) > 0) {
		return 1;
	}
	else{
	 	return 0;
	}
}

//insertion function, performs balancing after node gets placed
TreeNode* Tree::insert(TreeNode* root, States *s) {
	if (root == nullptr) {
		TreeNode* node = new TreeNode(s);
		return node;
	}

	if (compareStateNames(s->getState(),root->state.getState()) == -1) {
		root->left = insert(root->left, s);
	}
	else if (compareStateNames(s->getState(), root->state.getState()) == 1) {
		root->right = insert(root->right, s);
	}
	else {
		return root;
	}

	//begin balancing by obtaining the balance value of the current node
	int b = balanceValue(root);

	//based off of the relationship of the balancevalue and the statenames, perform the appropriate rotation
	if (b < -1 && compareStateNames(s->getState(),root->right->state.getState()) == 1) {
		return leftRotate(root);
	}
	if (b > 1 && compareStateNames(s->getState(), root->left->state.getState()) == -1) {
		return rightRotate(root);
	}
	if (b < -1 && compareStateNames(s->getState(), root->right->state.getState()) == -1) {
		return rightLeftRotate(root);
	}
	if (b > 1 && compareStateNames(s->getState(), root->left->state.getState()) == 1) {
		return leftRightRotate(root);
	}

	return root;
}

//helper function for actual remove
TreeNode* Tree::remove(TreeNode* root, std::string statename){
	std::vector<TreeNode*> storedTree;

	//actual remove happens in removeStuff
	removeStuff(root, statename);

	//These functions create a balanced tree
	store(storedTree, root);
	return makeTree(storedTree, 0, (int)storedTree.size() - 1);
}

//base condition that prints unsuccessful if statename not found
TreeNode* Tree::removeStuff(TreeNode* root, std::string statename) {
	if (root == nullptr) {
		std::cout << "unsuccessful" << std::endl;
		return root;
	}

	//compares statename to current node's statename and recursively checks next nodes
	if (compareStateNames(statename, root->state.getState()) == -1) {
		root->left = removeStuff(root->left, statename);
		return root;
	}
	else if (compareStateNames(statename, root->state.getState()) == 1) {
		root->right = removeStuff(root->right, statename);
		return root;
	}
	//if equal, preforms a remove operation
	else {
		//first two cases are for nodes that have one or no children
		if (root->right == nullptr) {
			TreeNode* t = root->left;
			delete root;
			return t;
		}
		else if (root->left == nullptr) {
			TreeNode* t = root->right;
			delete root;
			return t;
		}
		TreeNode* t = findInorderSuccessor(root->right);
		//replaces root values with Inorder successor values
		root->state = t->state;

		//goes searching for old inorder successor position to delete it
		root->right = removeStuff(root->right, root->state.getState());

		return root;
	}
}

//searches the Tree for the node with the input statename
TreeNode* Tree::search(TreeNode* root, std::string statename) {
	if (root != nullptr) {
		if (compareStateNames(statename, root->state.getState()) == 0) {
			return root;
		}
		if (compareStateNames(statename, root->state.getState()) == -1) {
			root = search(root->left, statename);
			return root;
		}
		else {
			root = search(root->right, statename);
			return root;
		}
	}
}

//Prints elements inOrder
void Tree::printInorder(TreeNode* root, std::string& s) {
	//base condition
	if (root == nullptr) {
		return;
	}
	//traverses the tree in order and adds to string
	printInorder(root->left, s);
	s = s + root->state.getState() + ", ";
	printInorder(root->right, s);
}

//finds the inorder successor by searching most left element in right child of root
TreeNode* Tree::findInorderSuccessor(TreeNode* root) {
	TreeNode* t = root;
	while (t && t->left != nullptr) {
		t = t->left;
	}
	return t;
}

//checks the height recursively in the children and returns the larger value + 1 to add the current position
int Tree::height(TreeNode* root) {
	//base condition
	if (root == nullptr) {
		return 0;
	}
	else {
		int l = height(root->left);
		int r = height(root->right);
		if (l > r) {
			return 1 + l;
		}
		else {
			return 1 + r;
		}
	}
}

//returns the heights of the children and returns the difference
int Tree::balanceValue(TreeNode* root) {
	int l = height(root->left);
	int r = height(root->right);
	return l - r;
}

//stores the tree in a vector of TreeNodes
void Tree::store(std::vector<TreeNode*>& storedTree, TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	store(storedTree, root->left);
	storedTree.push_back(root);
	store(storedTree, root->right);
}

//recreates the tree from the vector of TreeNodes recursively
TreeNode* Tree::makeTree(std::vector<TreeNode*>& storedTree, int begin, int end) {
	//base case
	if (begin > end) {
		return nullptr;
	}
	int middle = (begin + end) / 2;
	TreeNode* root = storedTree[middle];

	root->left = makeTree(storedTree, begin, middle - 1);
	root->right = makeTree(storedTree, middle + 1, end);

	return root;
}

//performs a left rotation
TreeNode* Tree::leftRotate(TreeNode* root) {
	TreeNode* temp = root->right->left;
	TreeNode* nParent = root->right;
	nParent->left = root;
	root->right = temp;
	return nParent;
}

//preforms a right rotation
TreeNode* Tree::rightRotate(TreeNode* root) {
	TreeNode* temp = root->left->right;
	TreeNode* nParent = root->left;
	nParent->right = root;
	root->left = temp;
	return nParent;
}

//performs a left right rotation
TreeNode* Tree::leftRightRotate(TreeNode* root) {
	root->left = leftRotate(root->left);
	return rightRotate(root);
}

//preforms a right left rotation
TreeNode* Tree::rightLeftRotate(TreeNode* root) {
	root->right = rightRotate(root->right);
	return leftRotate(root);
}

//Iterates through the AVL tree of state Nodes to acquire National Election data
void Tree::nationalInfoAVL(TreeNode* root, int* info) {
	if (root == nullptr)
		return;

	nationalInfoAVL(root->left, info);

	info[0] += root->state.getDemPresVotes();
	info[1] += root->state.getRepPresVotes();
	info[2] += root->state.getOtherPresVotes();

	nationalInfoAVL(root->right, info);
}

//Iterates through the AVL Tree of states to acquire Senatorial Election data
void Tree::senatorialInfoAVL(TreeNode* root, bool search) {
	if (root == nullptr)
		return;

	senatorialInfoAVL(root->left, search);
	if (search) {
		if (root->state.getDemSenator().compare("NONE") != 0 && root->state.getRepSenator().compare("NONE") != 0) {
			std::cout << "\nSenatorial Election Data for " << root->state.getState() << ": " << std::endl;
			printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", root->state.getDemSenator().c_str(), root->state.getDemSenVotes(), root->state.getPercent(3));
			printf("Candidate Name: %-25s | Vote Count: %-5d | Vote Percentage: %.2f%% \n", root->state.getRepSenator().c_str(), root->state.getRepSenVotes(), root->state.getPercent(4));
			printf("Candidate Name: Other                     | Vote Count: %-5d | Vote Percentage: %.2f%% \n", root->state.getOtherSenVotes(), root->state.getPercent(5));
		}
		else {
			std::cout << "\nNo Senatorial Election Data available for " << root->state.getState() << "." << std::endl;
		}
	}
	senatorialInfoAVL(root->right, search);
}

