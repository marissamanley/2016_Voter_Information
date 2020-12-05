#pragma once
#include "TreeNode.h"
using namespace std;
class Tree
{
public:
	TreeNode* root;
	int count;
	Tree();
	int compareStateNames(string one, string two);
	TreeNode* insert(TreeNode* root, States *s);
	TreeNode* remove(TreeNode* root, string statename);
	TreeNode* removeStuff(TreeNode* root, string statename);
	TreeNode* search(TreeNode* root, string statename);
	void printInorder(TreeNode* root, string& s);
	TreeNode* findInorderSuccessor(TreeNode* root);
	int height(TreeNode* root);
	int balanceValue(TreeNode* root);
	void store(std::vector<TreeNode*>& storedTree, TreeNode* root);
	TreeNode* makeTree(std::vector<TreeNode*>& tree, int begin, int end);
	TreeNode* leftRotate(TreeNode* root);
	TreeNode* rightRotate(TreeNode* root);
	TreeNode* leftRightRotate(TreeNode* root);
	TreeNode* rightLeftRotate(TreeNode* root);
   
};

