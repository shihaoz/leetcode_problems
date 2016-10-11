//
//  airbnb_house_robber.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "airbnb_house_robber.hpp"

class Solution {
    /**
     method 1:
        at idx, rob or not (recursion)
     */
    void _recursion(int i , vector<int>& nums, int amount);
    int _maxAmount;
    /**
     method 2:
     
     */
public:
    int rob1(vector<int>& nums) {
        _maxAmount = 0;
        this->_recursion(0, nums, 0);
        return _maxAmount;
    }
    
    int rob2(vector<int>& nums){
        _maxAmount = 0;
        if (!nums.empty()) {
//            vector<int> maxRob(nums.size()+2);
            int now = 0, next = 0, nextNext = 0;
//            maxRob[0] = 0;
            for (int i = 0; i < nums.size(); i++) {
//                maxRob[i+2] = max(maxRob[i+2], maxRob[i] + nums[i]);
//                maxRob[i+1] = max(maxRob[i+1], maxRob[i]);
                next = max(next, now);
                nextNext = max(nextNext, now + nums[i]);
                now = next; next = nextNext;
                nextNext = 0;
            }
//            _maxAmount = max(maxRob[nums.size()], maxRob[nums.size()+1]);
            _maxAmount = max(now, next);
        }
        
        return _maxAmount;
    }
};
void Solution::_recursion(int i, vector<int> &nums, int amount){
    if (i >= nums.size()) { // end:
        _maxAmount = max(this->_maxAmount, amount);
    }
    else{
        this->_recursion(i+2, nums, amount + nums[i]);  // rob here
        this->_recursion(i+1, nums, amount);    // not rob here
    }
}

const vector<vector<int>> _testcases = {
    {5, 3, 7,0, 4, 3, 5},
    {2,3,2},
    {1, 1, 0, 2, 7},
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.rob2(test) << "\n";
    }
    return 0;
}