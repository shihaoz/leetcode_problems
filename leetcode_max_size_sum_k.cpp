//
//  leetcode_max_size_sum_k.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/12/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_max_size_sum_k.hpp"

class Solution {
    
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        int max_length = 0, sum = 0;
        unordered_map<int, int> _lookup; // <pre_sum, index>
        _lookup[0] = -1;    // sum = zero when nothing is present
        vector<int> _pre_sum;
        
        for (int i = 0; i < nums.size(); i++) {
            // update sum
            _pre_sum.push_back(sum + nums[i]);
            sum += nums[i];
            
            // update lookup
            if (_lookup.find(_pre_sum[i]) == _lookup.end()) {
                _lookup[_pre_sum[i]] = i;
            }
            // find if complement exists
            if (_lookup.find(_pre_sum[i] - k) != _lookup.end()) {
                max_length = max(max_length, i - _lookup[_pre_sum[i] - k]);
            }
        }
        return max_length;
    }
};


struct TEST {
    vector<int> inputs;
    int k;
};
const vector<TEST> _testcases = {
    {
        {1, -1, 5, -2, 3}, 3,   // 3
    },
    {
        {-2, -1, 2, 1}, 1,      // 1
    },
    {
        {10, -9, 8, -5, -3, 6}, 100,    // 0
    },
    {
        {10, -9, 8, -5, -3, 6}, -3,    // 5
    },
    {
        {8}, 10  // 0
    }
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.maxSubArrayLen(test.inputs, test.k) << "\n";
    }
    return 0;
}