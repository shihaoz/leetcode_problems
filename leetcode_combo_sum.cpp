//
//  leetcode_combo_sum.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/24/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_combo_sum.hpp"

class Solution {
    void _helper(unordered_map<int, int>::iterator it_now, unordered_map<int, int>::iterator it_end,
                 int target, int sum, vector<int> combo, vector<vector<int>>& answ);
public:
    vector<vector<int>> combinationSum2_slower(vector<int>& candidates, int target){
        if (target <= 0 or candidates.empty()) {
            return {};
        }
        unordered_map<int, int> _table; vector<vector<int>> answ;
        for (int i : candidates) {
            _table[i]++;
        }
        
        this->_helper(_table.begin(), _table.end(), target, 0, {}, answ);
        return answ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        if (target <= 0 or candidates.empty()) {
            return {};
        }
        unordered_map<int, int> _table;
        vector<vector<int>> answ, blocks(1, vector<int>(1, 0));
        for (int i : candidates) {
            _table[i]++;
        }
        for (auto it = _table.begin(); it != _table.end(); it++) {
            int size = blocks.size();
            for (int i = 0; i < size; i++) {
                // for every existing element, append as long as sum <= target
                vector<int> tmp = blocks[i];
                int j = 1, sum = blocks[i].back();
                for (;
                     j <= it->second and sum + it->first < target;
                     j++) {
                    sum += it->first;
                    tmp.back() = it->first; tmp.push_back(sum);
                    blocks.push_back(tmp);
                }
                // check the next one
                sum += it->first;
                if (j <= it->second and sum == target) {
                    tmp.back() = it->first;
                    answ.push_back(tmp);
                }
            }
        }
        return answ;
    }
};

void Solution::_helper(unordered_map<int, int>::iterator it_now, unordered_map<int, int>::iterator it_end,
                       int target, int sum, vector<int> combo, vector<vector<int> > &answ){
    if (sum == target) {
        answ.push_back(combo);
    }
    else if(it_now != it_end and sum < target){
        int value = it_now->first, count = it_now->second;
        it_now++;
        for (int i = 0; i <= count; i++) {
            this->_helper(it_now, it_end, target, sum + i*value, combo, answ);
            combo.push_back(value);
        }
    }
}
struct TEST {
    vector<int> inputs;
    int target;
};
const vector<TEST> _testcases = {
//    {
//        {1, 2, 2, 3},
//        4,
//    },
//    {
//        {10, 1, 2, 7, 6, 1, 5, 11, 12, 13, 14, 15, 16, 17, 18},
//        8,
//    },
//    {
//        {7, 8, 9},
//        5,
//    },
    {
        {1,1,1,1,1},
        3,
    },
    {
        {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12},
        27
    }
};
int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        dzCommon::printArrayArray(solve.combinationSum2(test.inputs, test.target), true);
    }
    return 0;
}