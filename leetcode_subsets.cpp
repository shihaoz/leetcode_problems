//
//  leetcode_subsets.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_subsets.hpp"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        
        // setup
        vector<vector<int>> _answ;
        _answ.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            int size = _answ.size();
            for (int j = 0; j < size; j++) {
                // use i
                _answ.push_back({_answ[j]});
                _answ.back().push_back(nums[i]);
            }
        }
        return _answ;
    }
};

const vector<vector<int>> _testcases = {
    {
        1,2,3,
    },
    {
        1,
    },
    {
        1,1,1,
    }
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        dzCommon::printArrayArray(solve.subsets(test), true);
    }
    return 0;
}