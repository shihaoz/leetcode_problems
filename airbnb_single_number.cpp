//
//  airbnb_single_number.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "airbnb_single_number.hpp"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int thatNumber = 0;
        for (int i = 0; i < nums.size(); i++) {
            thatNumber = thatNumber ^ nums[i];
        }
        return thatNumber;
    }
};

const vector<vector<int>> _testcases = {
    {
        1,2,3,2,1,
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.singleNumber(test) << '\n';
    }
    return 0;
}