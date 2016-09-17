//
//  subset_sum.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/16/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "subset_sum.hpp"
class Solution{
public:
    bool subsetSum(vector<int> values, int target);
};

bool Solution::subsetSum(vector<int> values, int target){
    if (values.empty()) {
        return false;
    }
    // setup
    vector<vector<bool>> _states(values.size(), vector<bool>(target+1, false));
    _states[0][0] = true;
    if (values[0] <= target) {
        _states[0][values[0]] = true;
    }
    for (int i = 0; i < values.size()-1; i++) {
        if (_states[i][target]) {
            return true;
        }
        for (int j = 0; j < target+1; j++) {
            if (_states[i][j]) {
                // not taking this value
                _states[i+1][j] = true;
                if (j + values[i+1] <= target) {
                    // taking this value
                    _states[i+1][j+values[i+1]] = true;
                }
            }
        }
    }
    return _states[values.size()-1][target];
}
struct TEST {
    vector<int> inputs;
    int target;
};

const vector<TEST> _testcases = {
    {
        {3,2,7,1}, 6,
    },
    {
        {3,2,7,1}, 15,
    },
    {
        {3, 3, 3, 3}, 11,
    },
    {
        {10}, 10
    },
    {
        {10, 5, 10, 3}, 14
    },
    {
        {1,1,1,1,1}, 3
    }
};
int main(){
    Solution solve; cout << boolalpha;
    
    for (auto test : _testcases) {
        cout << solve.subsetSum(test.inputs, test.target) << "\n";
    }
    return 0;
}