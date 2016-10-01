//
//  leetcode_3sum_smaller.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_3sum_smaller.hpp"

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size()-2; i++) {
            int left = i+1, right = nums.size()-1;
            int sum = nums[i]+nums[left]+nums[right];
            while (left < right) {
                if (sum < target) {// add all [left+1, right]
                    count += right - left;
                    sum += nums[left+1] - nums[left];
                    left++;
                }
                else{    // sum >= target
                    sum -= nums[right] - nums[right-1];
                    --right;
                }
            }
        }
        return count;
    }
};
struct TEST {
    vector<int> nums;
    int target;
};
const vector<TEST> _testcases = {
    {
        {-2, 0, 1, 3},
        2,
    },
    {
        {1,2,3,4},
        8,
    },
    {
        {1,2,3},
        3,
    },
    {
        {},
        0,
    }
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.threeSumSmaller(test.nums, test.target) << '\n';
    }
    return 0;
}