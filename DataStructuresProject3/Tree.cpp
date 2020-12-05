#include "Tree.h"
Tree::Tree()
{
	//Default constructor
	root = nullptr;
}
int Tree::compareStateNames(string one, string two)
{
	if (one.compare(two) < 0)
	{
		return -1;
	}
	else if (one.compare(two) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
TreeNode* Tree::insert(TreeNode* root, States *s)
{
	if (root == nullptr)
	{
		TreeNode* node = new TreeNode(s);
		return node;
	}
	if (compareStateNames(s->getState(),root->state.getState()) == -1)
	{
		root->left = insert(root->left, s);
	}
	else if (compareStateNames(s->getState(), root->state.getState()) == 1)
	{
		root->right = insert(root->right, s);
	}
	else
	{
		std::cout << "unsuccessful" << std::endl;
		return root;
	}

	//begin balancing by obtaining the balance value of the current node
	int b = balanceValue(root);

	//based off of the relationship of the balancevalue and the IDs, perform the appropriate rotation
	if (b < -1 && compareStateNames(s->getState(),root->right->state.getState()) == 1)
	{
		return leftRotate(root);
	}

	if (b > 1 && compareStateNames(s->getState(), root->left->state.getState()) == -1)
	{
		return rightRotate(root);
	}

	if (b < -1 && compareStateNames(s->getState(), root->right->state.getState()) == -1)
	{
		return rightLeftRotate(root);
	}

	if (b > 1 && compareStateNames(s->getState(), root->left->state.getState()) == 1)
	{
		return leftRightRotate(root);
	}

	return root;
}

TreeNode* Tree::remove(TreeNode* root, string statename)
{
	//helper function for actual remove

	std::vector<TreeNode*> storedTree;

	//actual remove happens in removeStuff
	removeStuff(root, statename);

	//These functions create a balanced tree
	store(storedTree, root);
	return makeTree(storedTree, 0, storedTree.size() - 1);

}

TreeNode* Tree::removeStuff(TreeNode* root, string statename)
{
	//base condition that prints unsuccessful if ID not found
	if (root == nullptr)
	{
		std::cout << "unsuccessful" << std::endl;
		return root;
	}

	//compares ID to current node's ID and recursively checks next nodes
	if (compareStateNames(statename, root->state.getState()) == -1)
	{
		root->left = removeStuff(root->left, statename);
		return root;
	}
	else if (compareStateNames(statename, root->state.getState()) == 1)
	{
		root->right = removeStuff(root->right, statename);
		return root;
	}
	//if equal, preforms a remove operation
	else
	{
		//first two cases are for nodes that have one or no children
		if (root->right == nullptr)
		{
			TreeNode* t = root->left;
			delete root;
			//std::cout << "successful" << std::endl;
			return t;
		}
		else if (root->left == nullptr)
		{
			TreeNode* t = root->right;
			delete root;
			//std::cout << "successful" << std::endl;
			return t;
		}
		//This case is for nodes that have two children
		TreeNode* t = findInorderSuccessor(root->right);

		//replaces root values with Inorder successor values
		root->state = t->state;

		//goes searching for old inorder successor position to delete it
		root->right = removeStuff(root->right, root->state.getState());

		return root;
	}
}

TreeNode* Tree::search(TreeNode* root, string statename)
{
	//base condition that prints unsuccessful if ID not found
	if (root == nullptr)
	{
		std::cout << "unsuccessful" << std::endl;
		return root;
	}

	//compares IDs and searches recursively if not matching
	if (compareStateNames(statename, root->state.getState()) == 0)
	{
		return root;
	}
	else if (compareStateNames(statename, root->state.getState()) == -1)
	{
		search(root->left, statename);
	}
	else
	{
		search(root->right, statename);
	}

}

void Tree::printInorder(TreeNode* root, std::string& s) //This might be used
{
	//base condition
	if (root == nullptr)
	{
		return;
	}

	//traverses the tree in order and adds to string
	printInorder(root->left, s);

	s = s + root->state.getState() + ", ";

	printInorder(root->right, s);
}

TreeNode* Tree::findInorderSuccessor(TreeNode* root)
{
	//finds the inorder successor by searching most left element in right child of root
	TreeNode* t = root;

	while (t && t->left != nullptr)
	{
		t = t->left;
	}
	return t;
}

int Tree::height(TreeNode* root)
{
	//base condition
	if (root == nullptr)
	{
		return 0;
	}
	//checks the height recursively in the children and returns the larger value + 1 to add the current position
	else
	{
		int l = height(root->left);
		int r = height(root->right);
		if (l > r)
		{
			return 1 + l;
		}
		else
		{
			return 1 + r;
		}
	}
}

int Tree::balanceValue(TreeNode* root)
{
	//gets the heights of the children and returns the difference
	int l = height(root->left);
	int r = height(root->right);
	return l - r;
}

void Tree::store(std::vector<TreeNode*>& storedTree, TreeNode* root)
{
	//stores the tree in a vector of TreeNodes
	if (root == nullptr)
	{
		return;
	}
	store(storedTree, root->left);
	storedTree.push_back(root);
	store(storedTree, root->right);

}

TreeNode* Tree::makeTree(std::vector<TreeNode*>& storedTree, int begin, int end)
{
	//base case
	if (begin > end)
	{
		return nullptr;
	}

	//recreates the tree from the vector of TreeNodes recursively
	int middle = (begin + end) / 2;
	TreeNode* root = storedTree[middle];

	root->left = makeTree(storedTree, begin, middle - 1);
	root->right = makeTree(storedTree, middle + 1, end);

	return root;
}

TreeNode* Tree::leftRotate(TreeNode* root)
{
	//performs a left rotation
	TreeNode* temp = root->right->left;
	TreeNode* nParent = root->right;
	nParent->left = root;
	root->right = temp;
	return nParent;
}

TreeNode* Tree::rightRotate(TreeNode* root)
{
	//preforms a right rotation
	TreeNode* temp = root->left->right;
	TreeNode* nParent = root->left;
	nParent->right = root;
	root->left = temp;
	return nParent;
}

TreeNode* Tree::leftRightRotate(TreeNode* root)
{
	//performs a left right rotation
	root->left = leftRotate(root->left);
	return rightRotate(root);
}

TreeNode* Tree::rightLeftRotate(TreeNode* root)
{
	//preforms a right left rotation
	root->right = rightRotate(root->right);
	return leftRotate(root);
}

