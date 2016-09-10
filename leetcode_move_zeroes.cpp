//
//  leetcode_move_zeroes.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_move_zeroes.hpp"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_idx = 0, idx = 0;
        while (zero_idx < nums.size() and nums[zero_idx] != 0) {
            zero_idx++; idx++;
        }idx++;
        if (zero_idx == nums.size()) {
            // no zeros
            return;
        }
        
        while (idx < nums.size() and zero_idx < nums.size()) {
            if (nums[idx]==0) {
            }
            else{
                if (zero_idx < idx) {
                    nums[zero_idx] = nums[idx];
                    nums[idx] = 0;
                    cout << "swap!\n";
                    // find next zero
                    while (zero_idx < nums.size() and nums[zero_idx] != 0) {
                        zero_idx++;
                    }
                }
            }
            idx++;
        }
    }
};
const vector<vector<int>> _testcases = {
    {0,1,0,3,12},
    {0,0,1,2,3},
    {1,2,3,0,0},
    {0,0,0,0,0},
    {0},
    {1},
};
int main(){
    Solution solve;
    
    for (auto v : _testcases) {
        solve.moveZeroes(v);
        for (int i : v) {
            cout << i << " ";
        }cout << "\n";
    }
    return 0;
}