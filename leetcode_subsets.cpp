//
//  leetcode_subsets.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/24/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_subsets.hpp"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> _answ(1, {});
        
        for (int next_num : nums) {
            int size = _answ.size();
            for (int i = 0; i < size; i++) {
                _answ.push_back(_answ[i]);
                _answ.back().push_back(next_num);
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
        4,1,5,
    }
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        dzCommon::printArrayArray(solve.subsets(test), true);
    }
    return 0;
}