//
//  leetcode_combination_sum4.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_combination_sum4.hpp"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty() or target <= 0) {
            return 0;
        }
        vector<int> _states(target+1, 0);
        _states[0] = 1;
        
        
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i-nums[j] >= 0) {
                    _states[i] += _states[i-nums[j]];
                }
            }
        }
        return _states[target];
    }
};

struct TEST {
    vector<int> inputs;
    int target;
};

const vector<TEST> _testcases = {
    {
        {1,2,3,},
        4
    },
    {
        {4},
        1
    },
    {
        {1},
        0
    }
};

int main(){
    Solution solve;
    
    for (TEST test : _testcases) {
        cout << solve.combinationSum4(test.inputs, test.target) << '\n';
    }
    return 0;
}