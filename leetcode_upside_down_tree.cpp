//
//  leetcode_upside_down_tree.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_upside_down_tree.hpp"
using namespace dzTree;
class Solution {
    TreeNode* _helper(TreeNode* root);
    TreeNode* _answ;
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        this->_answ = nullptr;
        if (root) {
            this->_helper(root);
            root->left = root->right = nullptr;
        }
        return this->_answ;
    }
};

TreeNode* Solution::_helper(TreeNode *root){
    if (!root->left) {
        this->_answ = root;
        return root;
    }
    else{
        TreeNode* newRoot = this->_helper(root->left);
        newRoot->left = root->right;
        if (newRoot->left) {
            newRoot->left->left = newRoot->left->right = nullptr;
        }
        newRoot->right = root;
        
        return root;
    }
}

int main(){
    
    return 0;
}