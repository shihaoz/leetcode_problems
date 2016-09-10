//
//  leetcode_summary_ranges.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_summary_ranges.hpp"

class Solution {
    void _store(vector<string>& answ, int left, int right){
        if (left == right) {
            answ.push_back(to_string(left));
        }
        else{
            answ.push_back(to_string(left) + "->" + to_string(right));
        }
    }
public:
    vector<string> summaryRanges_slow(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<string> answ;
        int left, right;    left = right = nums.front();

        for (int i = 0; i < nums.size(); i++, right++) {
            if (right != nums[i]) {
                this->_store(answ, left, right-1);
                left = right = nums[i];
            }
        }
        this->_store(answ, left, right-1);
        return answ;
    }
    
    vector<string> summaryRanges(vector<int>& nums){
        vector<string> answ;
        if (nums.empty()) {
            return {};
        }
        int last_idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] != 1) {
                if (i-1 == last_idx) {
                    answ.push_back(to_string(nums[last_idx]));
                }
                else{
                    answ.push_back(to_string(nums[last_idx]) + "->" + to_string(nums[i-1]));
                }
                last_idx = i;
            }
        }
        if (last_idx == nums.size()-1) {
            answ.push_back(to_string(nums[last_idx]));
        }
        else{
            answ.push_back(to_string(nums[last_idx]) + "->" + to_string(nums.back()));
        }
        return answ;
    }
};

const vector<vector<int>> _testcases = {
    {0,1,2,4,5,7},      // 0->2, 4->5, 7
    {0,1,2,3,4,5},      // 0->5
    {0, 3, 7, 9},       // 0, 3, 7, 9
    {0},                // 0
    {0,1},              // 0->1
};
void printArray(vector<string> in){
    for (string s : in) {
        cout << s << " ";
    }cout << "\n";
}

int main(){
    Solution solve;
    for (auto vec : _testcases) {
        printArray(solve.summaryRanges(vec));
    }
    return 0;
}