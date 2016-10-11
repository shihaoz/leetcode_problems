//
//  leetcode_house_robber2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_house_robber2.hpp"

using namespace dzTree;
struct robbery {
    int amountRob, amountNonRob;
};
class Solution {
    
    robbery _DFS(TreeNode* root);
public:
    int rob(TreeNode* root) {
        robbery gain = _DFS(root);
        return max(gain.amountRob, gain.amountNonRob);
    }
};
robbery Solution::_DFS(dzTree::TreeNode *root){
    if (!root) {
        return {0, 0};
    }
    if (!root->left and !root->right) {// leaf node
        return {root->val, 0};
    }
    robbery myGain,
    leftGain = this->_DFS(root->left),
    rightGain = this->_DFS(root->right);
    
    myGain.amountRob = root->val + leftGain.amountNonRob + rightGain.amountNonRob;
    myGain.amountNonRob = max(leftGain.amountNonRob, leftGain.amountRob) +
    max(rightGain.amountNonRob, rightGain.amountRob);
    return myGain;
}

int main(){
    Solution solve;
    
    vector<TreeNode> nodes(6);
    vector<int> inputs1 = {3,4,5,1,3,1};
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].val = inputs1[i];
    }
    nodes[0].left = &nodes[1]; nodes[0].right = &nodes[2];
    nodes[1].left = &nodes[3];   nodes[1].right = &nodes[4];
    nodes[2].right = &nodes[5];
    
    cout << solve.rob(&nodes[0]) << "\n";
    
    nodes = vector<TreeNode>(8);
    vector<int> inputs2 = {3,4,2,1,3,3,4,1};
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].val = inputs2[i];
    }
    nodes[0].left = &nodes[1]; nodes[0].right = &nodes[2];
    nodes[1].left = &nodes[3];   nodes[1].right = &nodes[4];
    nodes[2].right = &nodes[5];
    nodes[3].left = &nodes[6];   nodes[3].right = &nodes[7];
    
    cout << solve.rob(&nodes[0]) << '\n';
    return 0;
}