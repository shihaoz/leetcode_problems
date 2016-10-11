//
//  fb_sort_colors.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_sort_colors.hpp"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> buckets(3, 0);
        for (int i : nums) {
            buckets[i]++;
        }
        int idx = 0;
        for (int i = 0; i < buckets.size(); i++) {
            while (buckets[i]--) {
                nums[idx++] = i;
            }
        }
    }
    void sortColors2(vector<int>& nums){
        int a = 0, b = 0, c = nums.size()-1;
        while (b <= c) {
            if (nums[b] == 1) {
                b++;
            }
            else if(nums[b] == 0){
                swap(nums[b++], nums[a++]);
            }
            else{// == 2
                swap(nums[b], nums[c--]);
            }
        }
    }
};

const vector<vector<int>> _testcases = {
    {
        1,2,0,2,2,0,1,0,1,
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        solve.sortColors2(test);
        dzCommon::printArray(test,true);
    }
    return 0;
}