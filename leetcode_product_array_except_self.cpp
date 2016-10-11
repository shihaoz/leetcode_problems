//
//  leetcode_product_array_except_self.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_product_array_except_self.hpp"
#include "common.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answ(nums.size(), 1);
        for (int i = 0, product = 1; i < nums.size()-1; i++) {
            product *= nums[i];
            answ[i+1] = product;
        }
        for (int i = nums.size()-1, product = 1; i >= 0; i--) {
            product *= nums[i];
            answ[i-1] *= product;
        }
        return answ;
    }
};

const vector<vector<int>> _testcases = {
    {3,2,5,4},
    {1, -2, 3, -4},
    {1,2},
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        dzCommon::printArray(solve.productExceptSelf(test), true);
    }
    return 0;
}