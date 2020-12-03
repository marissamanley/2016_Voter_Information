#pragma once
#include "States.h"
class TreeNode
{
    public:
        States state;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        TreeNode();
        TreeNode(States s);
        TreeNode(States s, TreeNode* left, TreeNode* right);

    };
};

