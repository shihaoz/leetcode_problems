//
//  leetcode_hindex.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/15/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_hindex.hpp"
struct node{
    int val;
    int count, left_sum, right_sum;
    node* left, *right;
    node(int val): left(nullptr), right(nullptr), val(val), count(1)
        ,left_sum(0), right_sum(0){}
};
class Solution {
    void _addNew(node* here, int val);
    void _count(node* root, int length, int& answ);
    void _cleanUp(node* root);
public:

    int hIndex(vector<int>& citations) {
        if (citations.empty()) {
            return 0;
        }
        int answ = 0;
        node* root = new node(citations[0]);
        for (int i = 1; i < citations.size(); i++) {
            _addNew(root, citations[i]);
        }
        this->_count(root, 0, answ);
        this->_cleanUp(root);
        return answ;
    }
    
    int _hIndex(vector<int>& citations);
};
void Solution::_addNew(node *here, int val){
    if (here->val == val) {
        here->count++;
    }
    else{
        if (val < here->val) {
            here->left_sum++;
            if (here->left) {
                this->_addNew(here->left, val);
            }
            else{
                here->left = new node(val);
            }
        }
        else{
            here->right_sum++;
            if (here->right) {
                this->_addNew(here->right, val);
            }
            else{
                here->right = new node(val);
            }
        }
    }
}
void Solution::_count(node *root, int length, int& answ){
    int right_sum = root->count + root->right_sum + length;
    answ = max(answ, min(right_sum, root->val));
    
    if (root->left) {
        this->_count(root->left, right_sum, answ);
    }
    if (root->right) {
        this->_count(root->right, length, answ);
    }
}
void Solution::_cleanUp(node *root){
    if (root->left) {
        this->_cleanUp(root->left);
    }
    if (root->right) {
        this->_cleanUp(root->right);
    }
    delete root;
}

int Solution::_hIndex(vector<int> &citations){
    if (citations.empty()) {
        return 0;
    }
    vector<int> _stacks(citations.size()+1, 0);    int answ;
    int end = citations.size();
    for (int i : citations) {
        if (i > end) {
            _stacks[end]++;
        }
        else{
            _stacks[i]++;
        }
    }
    for (int i = _stacks.size()-1; i >= 1; i--) {
        if (_stacks[i] >= i) {
            return i;
        }
        _stacks[i-1] += _stacks[i];
    }
    return 0;
}

const vector<vector<int>> _testcases = {
    {
        3, 0, 6, 1, 5
    },
    {
        100,
    },
    {
        5, 4, 3, 2, 6, 10, 2,
    },
    {
        100, 99, 98
    },
    {
        0,
    }
};
int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        cout << solve._hIndex(test) << "\n";
    }
    return 0;
}