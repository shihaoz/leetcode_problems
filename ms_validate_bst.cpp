//
//  ms_validate_bst.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_validate_bst.hpp"
using namespace dzTree;

class Solution {
    bool _helper(long lower_bound, long upper_bound, TreeNode* root);
public:
    bool isValidBST(TreeNode* root) {
        return this->_helper(numeric_limits<long>::min(), numeric_limits<long>::max(), root);
    }
};
bool Solution::_helper(long lower_bound, long upper_bound, TreeNode *root){
    if (!root) {
        return true;    // null root
    }
    if ((long)root->val <= lower_bound or (long)root->val >= upper_bound) {
        return false;
    }
    return this->_helper(root->val, upper_bound, root->right) and
    this->_helper(lower_bound, root->val, root->left);
}

int main(){
    
    return 0;
}