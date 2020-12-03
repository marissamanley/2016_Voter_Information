#include "TreeNode.h"

TreeNode::TreeNode()
{
}

TreeNode::TreeNode(States *s)
{
	state = *s;
}

TreeNode::TreeNode(States* s, TreeNode* left, TreeNode* right)
{
	state = *s;
	this->left = left;
	this->right = right;
}
