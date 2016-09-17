//
//  max_product_cut.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/17/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "max_product_cut.hpp"

class Solution{
    
public:
    int maxProduct(int length);
};

int Solution::maxProduct(int length){
    if (length <= 1) {
        return 0;
    }
    
    // set up
    vector<int> _states(length+1, 0);   _states[0] = 1;
    
    // loop over all possible cut (with at least one cut)
    for (int cut = 1; cut < length; cut++) {
        for (int i = 0; i < _states.size() and i + cut <= length; i++) {
            if (_states[i] > 0) {
                _states[i+cut] = max(_states[i+cut], _states[i] * cut);
            }
        }
    }
    return _states[length];
}

const vector<int> _testcases = {
    2,
    4,
    5,
    6,
    10,
    15,
};

int main(){
    Solution solve;
    for (int i : _testcases) {
        cout << solve.maxProduct(i) << "\n";
    }
    return 0;
}