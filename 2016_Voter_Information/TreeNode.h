#pragma once
#include "States.h"
class TreeNode {
    //the class for the AVL tree's node
    public:
        States state;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        TreeNode();
        TreeNode(States* s);
        TreeNode(States* s, TreeNode* left, TreeNode* right);
};

