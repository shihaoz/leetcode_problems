//
//  fb_binary_tree_path.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_binary_tree_path.hpp"
using namespace dzTree;

class Solution {
    vector<string> _answ;
    void _DFS(TreeNode* root, string path);
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        this->_answ.clear();
        if (root) {
            this->_DFS(root, "");
        }
        return this->_answ;
    }
};
void Solution::_DFS(dzTree::TreeNode *root, string path){
    /// check if this is root
    path += to_string(root->val);
    if (root->left == nullptr and root->right == nullptr) {
        this->_answ.push_back(path);
    }
    else{
        path += "->";
        if (root->left) {
            this->_DFS(root->left, path);
        }
        if (root->right) {
            this->_DFS(root->right, path);
        }
    }
}