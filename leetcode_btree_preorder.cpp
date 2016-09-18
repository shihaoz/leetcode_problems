//
//  leetcode_btree_preorder.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_btree_preorder.hpp"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> answ;
        stack<TreeNode*> _candidates;
        answ.push_back(root->val);
        _candidates.push(root->right);   _candidates.push(root->left);
        
        while (!_candidates.empty()) {
            TreeNode* hold = _candidates.top();   _candidates.pop();
                answ.push_back(hold->val);
            if (hold->right) {
                _candidates.push(hold->right);
            }
            if (hold->left) {
                _candidates.push(hold->left);
            }
        }
        return answ;
    }
};

int main(){
    Solution solve;
    
    
    return 0;
}