//
//  leetcode_3sum.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_3sum.hpp"

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        vector<vector<int>> answ;
        sort(nums.begin(), nums.end());
        
        int last_element = nums[0]+1;
        for (int i = 0; i < nums.size()-2; i++) {
            int ele = nums[i];
            if (last_element == ele) {
                // don't do anything
            }
            else{
                int left_idx = i+1, right_idx = nums.size()-1;
                int left_last = nums[left_idx]+1, right_last = nums[right_idx]+1;
                while (left_idx < right_idx) {
                    int left_now = nums[left_idx], right_now = nums[right_idx];
                    if (left_now + right_now < -1*ele) {
                        // too small
                        left_idx++;
                    }
                    else if (left_now + right_now > -1*ele){
                        // too big
                        right_idx--;
                    }
                    else{
                        if (left_now != left_last or right_now != right_last) {
                            answ.push_back({ele, left_now, right_now});
                        }
                        left_idx++; right_idx--;
                    }
                    left_last = left_now;
                    right_last = right_now;
                }
            }
            last_element = ele;
        }
        
        return answ;
    }
};
const vector<vector<int>> _testcases = {
    {-1, 0, 1, 2, -1, -4},
    {-1, -1, -1, 0, 2},
    {0},
    {1,-1, 0},
    {-1, 0, 0, 1, 1, 1},
    {1, -1, -1, 0},
};
const string separator = "---------------------\n";
int main(){
    Solution solve;
    for (auto test : _testcases) {
        auto ret = solve.threeSum(test);
        for (auto& vec : ret) {
            for (int i : vec) {
                cout << i << " ";
            }cout << "\n";
        }
        cout << separator;
    }
    return 0;
}