//
//  leetcode_min_size_sub_sum.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/13/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_min_size_sub_sum.hpp"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> _pre_sum(1, 0);
        _pre_sum.reserve(nums.size()+1);
        int min_length = nums.size(), left_bound = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            _pre_sum.push_back(_pre_sum.back() + nums[i]);
            int t = _pre_sum.back() - s;
            if (t >= 0) {
                while (_pre_sum[left_bound] <= t) {
                    left_bound++;
                }
                left_bound--;
                min_length = min(min_length, i-left_bound+1);
            }
        }
        return (_pre_sum.back() >= s) ? min_length : 0;
    }
};
struct TEST {
    vector<int> inputs;
    int s;
};
const vector<TEST> _testcases = {
    {
        {2,3,1,2,4,3}, 7,
    },
    {
        {0, 7}, 5
    },
    {
        {1, 2, 3, 4, 5}, 11,
    },
    {
        {2, 3, 1, 1, 1, 1,}, 5,
    },
    {
        {1, 2,}, 5,
    }
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        cout << solve.minSubArrayLen(test.s, test.inputs) << '\n';
    }
    return 0;
}