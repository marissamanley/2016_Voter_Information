#include "TreeNode.h"

//default constructor
TreeNode::TreeNode()
{
}

//overload constructor when state pointer is given
TreeNode::TreeNode(States *s)
{
	state = *s;
}

//overload constructor when state pointer and left and right nodes are given
TreeNode::TreeNode(States* s, TreeNode* left, TreeNode* right)
{
	state = *s;
	this->left = left;
	this->right = right;
}
