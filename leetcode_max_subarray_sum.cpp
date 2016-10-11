//
//  leetcode_max_subarray_sum.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_max_subarray_sum.hpp"
#include "common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = numeric_limits<int>::min();
        int sumSoFar = 0, minSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sumSoFar += nums[i];
            maxSum = max(maxSum, sumSoFar);
            if (minSum < 0) {
                maxSum = max(maxSum, sumSoFar - minSum);
            }
            minSum = min(minSum, sumSoFar);
        }
        return maxSum;
    }
};

const vector<vector<int>> _testcases = {
    {-2,1,-3,4,-1,2,1,-5,4},
    {},
    {5},
    {-1},
    {-1, -5, -6, 10},
    {-1, -5, -6},
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.maxSubArray(test) << '\n';
    }
    return 0;
}