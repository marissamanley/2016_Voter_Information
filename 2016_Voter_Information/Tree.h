#pragma once
#include "TreeNode.h"
// The AVL Tree class
//* This class is the implementation of the AVL tree used as the secondary storage
//* option. The tree mostly performs insertion, searches, and traversals, but it also 
//* has the capability to remove if needed. Also performs self balancing.
//
// This code was modified from Mark Itkin's Project 1 submission
class Tree {
public:
	TreeNode* root;
	int count;
	Tree();
	int compareStateNames(std::string one, std::string two);
	TreeNode* insert(TreeNode* root, States *s);
	TreeNode* remove(TreeNode* root, std::string statename);
	TreeNode* removeStuff(TreeNode* root, std::string statename);
	TreeNode* search(TreeNode* root, std::string statename);
	void printInorder(TreeNode* root, std::string& s);
	TreeNode* findInorderSuccessor(TreeNode* root);
	int height(TreeNode* root);
	int balanceValue(TreeNode* root);
	void store(std::vector<TreeNode*>& storedTree, TreeNode* root);
	TreeNode* makeTree(std::vector<TreeNode*>& tree, int begin, int end);
	TreeNode* leftRotate(TreeNode* root);
	TreeNode* rightRotate(TreeNode* root);
	TreeNode* leftRightRotate(TreeNode* root);
	TreeNode* rightLeftRotate(TreeNode* root);
	void senatorialInfoAVL(TreeNode* root, bool search);
	void nationalInfoAVL(TreeNode* root, int* info);
};

