//
//  airbnb_2sum.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "airbnb_2sum.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); i++) {
            if (mapping.find(target-nums[i]) != mapping.end()) {
                return {i, mapping[target-nums[i]]};
            }
            mapping[nums[i]] = i;
        }
        return {};
    }
};

struct TEST {
    vector<int> nums;
    int target;
};
const vector<TEST> _testcases = {
    {
        {2, 7, 11, 15},
        9,
    },
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        dzCommon::printArray(solve.twoSum(test.nums, test.target), true);
    }
    return 0;
}