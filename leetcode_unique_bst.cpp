//
//  leetcode_unique_bst.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/17/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_unique_bst.hpp"


class Solution {
    long _helper_recursive(int left, int right);
    static unordered_map<int, long> _results;
public:
    long numTrees(int n);
};
unordered_map<int, long> Solution::_results;
long Solution::_helper_recursive(int left, int right){
    if (left >= right) {
        return 1;
    }
    int size = right-left+1;
    if (this->_results.find(size) != this->_results.end()) {
        return this->_results[size];
    }
    long count = 0;
    for (int i = left; i <= right; i++) {
        count += this->_helper_recursive(left, i-1) * this->_helper_recursive(i+1, right);
    }
    this->_results[size] = count;
    return count;
}
long Solution::numTrees(int n){
    this->_results[2] = 2;
    this->_results[3] = 5;

    return this->_helper_recursive(1, n);
}

const vector<int> _testcases = {
    0,
    3,
    4,
    5,
    6,
    10,
    17,
};

int main(){
    Solution solve;
    
    for (int i : _testcases) {
        cout << solve.numTrees(i) << "\n";
    }
    return 0;
}