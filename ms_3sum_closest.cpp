//
//  ms_3sum_closest.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_3sum_closest.hpp"


class Solution {

public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = numeric_limits<int>::max(),
        sum_best = -1;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-2 and diff > 0; i++) {
            for (int j = i+1; j < nums.size()-1 and diff > 0; j++) {
                int this_target = target - (nums[i]+nums[j]);

                auto it = lower_bound(nums.begin()+j+1, nums.end(), this_target);  // find first >= element
                int idx = it-nums.begin();
                /// update
                if (idx-1 >= j+1 and abs(this_target - nums[idx-1]) < diff) {
                    sum_best = nums[i] + nums[j] + nums[idx-1];
                    diff = abs(this_target-nums[idx-1]);
                }
                if (idx < nums.size() and abs(this_target-nums[idx]) < diff) {
                    sum_best = nums[i] + nums[j] + nums[idx];
                    diff = abs(this_target-nums[idx]);
                }

            }
        }
        
        return sum_best;
    }
    int threeSumClosest2(vector<int>& nums, int target) {
        int diff = numeric_limits<int>::max(),
        sum_best = -1;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-2; i++) {
            int left = i+1, right = nums.size()-1;
            int sum_here = nums[i] + nums[left] + nums[right];
            while (left < right) {
                if (abs(sum_here - target) < diff) {    // update if possible
                    diff = abs(sum_here - target);
                    sum_best = sum_here;
                }
                if (sum_here < target) {
                    sum_here += (nums[left+1] - nums[left]);
                    left++;
                }
                else if (sum_here > target){
                    sum_here -= (nums[right] - nums[right-1]);
                    right--;
                }
                else {// ==
                    return target;
                }
            }
        }
        return sum_best;
    }
};
struct TEST {
    vector<int> nums;
    int target;
};
const vector<TEST> _testcases = {
    {
        {-1, 2, 1, -4},
        1,
    },
    {
        {5,4,0,2,1},
        -1,
    },
    {
        {1,2,-1},
        0,
    },
    {
        {0,1,2},
        3
    }
};
int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        cout << solve.threeSumClosest2(test.nums, test.target) << "\n";
    }
    return 0;
}