//
//  leetcode_subset.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_subset.hpp"


class Solution {
public:
    /**
     @require: Given a set of distinct integers, nums, return all possible subsets.
     
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answ;   answ.push_back({});
        for (int num : nums) {
            for (int i = 0, size = answ.size(); i < size; i++) {
                answ.push_back(answ[i]);
                answ.back().push_back(num);
            }
        }
        return answ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> _table;
        for (int i : nums) {
            _table[i]++;
        }
        vector<vector<int>> answ;   answ.push_back({});
        for (auto it = _table.begin(); it != _table.end(); it++) {
            for (int i = 0, size = answ.size(); i < size; i++) {
                vector<int> tmp;
                for (int j = 1; j <= it->second; j++) {
                    tmp.push_back(it->first);
                    answ.push_back(answ[i]);
                    answ.back().insert(answ.back().end(), tmp.begin(), tmp.end());
                }
            }
        }
        return answ;
    }
};

const vector<vector<int>> _testcases_distinct = {
    {
        1,2,3
    },
    {
        1,
    },
    {
        
    },
};
const vector<vector<int>> _testcases_dup = {
    {
        1,2,2,
    },
    {
        3,3,3,
    },
    {
        1,2,2,3,3,
    },
};
int main(){
    Solution solve;
    for (auto vec : _testcases_distinct) {
        dzCommon::printArrayArray(solve.subsets(vec), true);
    }
    dzCommon::printSeparator();
    for (auto vec : _testcases_dup) {
        dzCommon::printArrayArray(solve.subsetsWithDup(vec), true);
    }
    return 0;
}