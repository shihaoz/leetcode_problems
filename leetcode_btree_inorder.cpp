//
//  leetcode_btree_inorder.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_btree_inorder.hpp"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root);
};

vector<int> Solution::inorderTraversal(TreeNode *root){
    vector<int> _answ;
    if (!root) {
        return {};
    }
    stack<TreeNode*> _candidates;
    while (root) {
        _candidates.push(root);
        root = root->left;
    }
    while (_candidates.size() > 0) {
        TreeNode* hold = _candidates.top(); _candidates.pop();
        _answ.push_back(hold->val);
        root = hold->right;
        while (root) {
            _candidates.push(root);
            root = root->left;
        }
    }
    return _answ;
}