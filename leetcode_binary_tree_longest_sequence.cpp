//
//  leetcode_binary_tree_longest_sequence.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/6/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_binary_tree_longest_sequence.hpp"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    int _helper_dfs(TreeNode* here, int last_value, int length);
public:
    int longestConsecutive(TreeNode* root) {
        if (root) {
            return this->_helper_dfs(root, root->val-1, 0);
        }
        return 0;
    }
};
int Solution::_helper_dfs(TreeNode *here, int last_value, int length){
    if (!here) {
        return length;
    }
    length = ((here->val == last_value+1)? length+1 : 1);
    
    return max(length,
               max(this->_helper_dfs(here->left, here->val, length),
                   this->_helper_dfs(here->right, here->val, length)));
}
TreeNode* make_ptr(int value){
    return new TreeNode(value);
}
void recycle(vector<TreeNode*>& array){
    for (TreeNode* ptr : array) {
        delete ptr; ptr = nullptr;
    }
}
int main(){
    Solution solve;
    // test1:
    //[1,null,3,2,4,null,null,null,5]
    vector<TreeNode*> test1 = {
        make_ptr(1),
        make_ptr(3),
        make_ptr(2), make_ptr(4),
        make_ptr(5),
    };
    test1[0]->right = test1[1];
    test1[1]->left = test1[2];    test1[1]->right = test1[3];
    test1[3]->right = test1.back();
    
    cout << solve.longestConsecutive(test1.front()) << "\n";
    recycle(test1);
    
    // test2:
    // [2,null,3,2,null,1,null]
    vector<TreeNode*> test2 = {
        make_ptr(2),
        make_ptr(3),
        make_ptr(2),
        make_ptr(1),
    };
    test2[0]->right = test2[1];
    test2[1]->left = test2[2];
    test2[2]->left = test2.back();
    cout << solve.longestConsecutive(test2.front()) << "\n";
    recycle(test2);
    
    // test3:
    // [null]
    cout << solve.longestConsecutive(nullptr) << "\n";
    
    // test4:
    // [1,2,2]
    vector<TreeNode*> test3 = {
        make_ptr(1),
        make_ptr(2),
        make_ptr(2),
    };
    test3[0]->right = test3[1];
    test3[0]->left = test3[2];
    cout << solve.longestConsecutive(test3.front()) << "\n";
    recycle(test3);
    return 0;
}