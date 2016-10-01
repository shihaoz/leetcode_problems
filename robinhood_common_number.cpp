//
//  robinhood_common_number.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "robinhood_common_number.hpp"
#include "common.h"

class Solution {
    
    
public:
        // [1, 1] [1, 1], 1
    vector<int> findCommon(vector<int> list1, vector<int> list2){
        vector<int> answ;
        if (!list1.empty() and !list2.empty()) {
            unordered_set<int> _lookup;
            for (int i : list1) {
                _lookup.insert(i);
            }
            for (int i : list2) {
                if (_lookup.find(i) != _lookup.end()) {
                    answ.push_back(i);  // 1st time common
                    _lookup.erase(i);   // avoid duplicate
                }
            }
        }
        return answ;
    }
    
};

const vector<pair<vector<int>, vector<int>>> _testcases = {
    {
        {1,2,3,4,},
        {4,5,10,1},
    },
    {
        {},
        {1},
    },
    {
        {1,1,1,1,1,1},
        {4,1,1,1,1,1,4,},
    },
    {
        {1},
        {},
    },

};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        dzCommon::printArray(solve.findCommon(test.first, test.second), true);
    }
    return 0;
}