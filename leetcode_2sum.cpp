//
//  leetcode_2sum.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_2sum.hpp"

class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> _indexes;
        for (int i = 0; i < nums.size(); i++) {
            _indexes[nums[i]].push_back(i);
        }
        unordered_map<int, vector<int>>::iterator it = _indexes.begin();
        for (; it != _indexes.end(); it++) {
            if (_indexes.find(target - it->first) != _indexes.end()) {
                if (target - it->first != it->first) {
                    // not equal element
                    return {min(it->second.front(), _indexes[target-it->first].front()),
                        max(it->second.front(), _indexes[target-it->first].front())};
                }
                else{// equal element
                    if (it->second.size() > 1) {
                        return {it->second[0], it->second[1]};
                    }
                }
            }
        }
        return {};
    }
    
    vector<int> twoSum2(vector<int>& nums, int target){
        unordered_map<int, int> _indexes;
        for (int i = 0; i < nums.size(); i++) {
            if (_indexes.find(target - nums[i]) != _indexes.end()) {
                return {min(_indexes[target-nums[i]], i),
                        max(_indexes[target-nums[i]], i)};
            }
            _indexes[nums[i]] = i;
        }
        return {};
    }
};
void printArray(vector<int> in){
    for (int i : in) {
        cout << i << " ";
    }cout << "\n";
}
struct TEST {
    vector<int> inputs;
    int target;
};
const vector<TEST> _testcases = {
    {{2,7,11,15}, 9},   // {0, 1}
    {{1,2,3,4}, 0},     // {}
    {{-1, 0, 1, 2}, 3}, // {2,3}
    {{1, 1}, 2},        // {0, 1}
    {{0, 1, 2, 5, 2}, 4}, // {2,4}
};
int main(){
    Solution solve;
    for (auto t : _testcases) {
        printArray(solve.twoSum2(t.inputs, t.target));
    }
    return 0;
}