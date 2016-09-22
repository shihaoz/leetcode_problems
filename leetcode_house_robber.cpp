//
//  leetcode_house_robber.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/20/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_house_robber.hpp"

class Solution {
    int _rob(vector<int>& nums, int start, int end);
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // setup
        int prevRob = nums[0], prevNonrob = 0, nowRob = 0, nowNonRob = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            nowRob = nums[i] + prevNonrob;
            nowNonRob = max(prevNonrob, prevRob);
            prevRob = nowRob;
            prevNonrob = nowNonRob;
        }
        return max(prevRob, prevNonrob);
    }
    
    int rob2(vector<int>& nums){
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        // setup
        return max(_rob(nums, 0, nums.size()-2), _rob(nums, 1, nums.size()-1));
    }
};

int Solution::_rob(vector<int> &nums, int start, int end){
    if (end < start) {
        return 0;
    }
    int prevRob = nums[start], prevNonrob = 0, nowRob = 0, nowNonrob = 0;
    for (int i = start+1; i <= end; i++) {
        nowRob = nums[i] + prevNonrob;
        nowNonrob = max(prevNonrob, prevRob);
        prevRob = nowRob;
        prevNonrob = nowNonrob;
    }
    return max(prevRob, prevNonrob);
}