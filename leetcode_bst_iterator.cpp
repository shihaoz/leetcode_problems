//
//  leetcode_bst_iterator.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/2/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_bst_iterator.hpp"
using namespace dzTree;

class BSTIterator {
    stack<TreeNode*> _nodes;
    void _storeNodes(TreeNode* root);
public:
    BSTIterator(TreeNode *root) {
        this->_storeNodes(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !this->_nodes.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* ret = this->_nodes.top(); this->_nodes.pop();
        this->_storeNodes(ret->right);  //store right tree
        return ret->val;
    }
};

void BSTIterator::_storeNodes(TreeNode *root){
    while (root) {
        this->_nodes.push(root);
        root = root->left;
    }
}

int main(){
    vector<TreeNode*> nodes(7, nullptr);
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i] = new TreeNode(i);
    }
    nodes[3]->left = nodes[1];  nodes[3]->right = nodes[5];
    nodes[1]->left = nodes[0];  nodes[1]->right = nodes[2];
    nodes[5]->left = nodes[4];  nodes[5]->right = nodes[6];
    
    BSTIterator it(nodes[3]);
    while (it.hasNext()) {
        cout << it.next() << " ";
    }cout << '\n';
    return 0;
}
