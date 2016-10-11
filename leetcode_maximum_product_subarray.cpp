//
//  leetcode_maximum_product_subarray.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_maximum_product_subarray.hpp"


class Solution {
    
    int _maxProduct;
    void _recursion(vector<int>& nums, int idx, int product);
public:
    int maxProduct(vector<int>& nums) {
        _maxProduct = numeric_limits<int>::min();
//        if (nums.size() == 1) {
//            return nums[0];
//        }
        if (!nums.empty()) {
            pair<int, int> last = {1, 1};   // <minimum, maximum>
            for (int i = 0; i < nums.size(); i++) {
                int a = nums[i]*last.first, b = nums[i]*last.second;
                last = {
                    max(max(a, b), nums[i]), min(min(a, b), nums[i])
                };
                _maxProduct = max(max(last.first, last.second), _maxProduct);
            }
        }
        return _maxProduct;
    }
};

void Solution::_recursion(vector<int> &nums, int idx, int product){
    _maxProduct = max(_maxProduct, product);
    if (idx < nums.size()) {
        /// keep taking product
        _recursion(nums, idx+1, product * nums[idx]);
        /// not continuous so product := 1
        _recursion(nums, idx+1, 1);
    }
}

const vector<vector<int>> _testcases = {
    {2,3,-2,4},
    {2,3,-2,4,-5, 0, 10, 10, -1},
    {},
    {-1, -2, -3},
    {-5},
    {-2,0,-1},
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.maxProduct(test) << "\n";
    }
    return 0;
}