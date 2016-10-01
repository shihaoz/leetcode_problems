//
//  ms_lowest_common_ancestor.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_lowest_common_ancestor.hpp"
using namespace dzTree;

class Solution {
    TreeNode* answ;
    
    int _helper(TreeNode *root, TreeNode *p, TreeNode *q);
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        answ = nullptr;
        this->_helper(root, p, q);
        return answ;
    }
};

int Solution::_helper(TreeNode *root, TreeNode *p, TreeNode *q){
    int count = 0;
    if (!root) {
        return count;
    }
    if (root == p or root == q) {
        count++;
    }
    if (root->left) {
        count += this->_helper(root->left, p, q);
    }
    if (root->right) {
        count += this->_helper(root->right, p, q);
    }
    if (count == 2 and this->answ == nullptr) {
        answ = root;
    }
    return count;
}

