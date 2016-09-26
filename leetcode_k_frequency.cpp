//
//  leetcode_k_frequency.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_k_frequency.hpp"
class cmp{
public:
    bool operator()(pair<int, int> left, pair<int, int> right){
        return left.second > right.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> _table;
        for (int i : nums) {
            _table[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> _max_heap;
        for (auto it = _table.begin(); it != _table.end(); it++) {
            _max_heap.push(make_pair(it->first, it->second));
            if (_max_heap.size() > k) {
                _max_heap.pop();
            }
        }
        vector<int> answ(_max_heap.size());
        for (int i = _max_heap.size()-1; i >= 0; i--, _max_heap.pop()) {
            answ[i] = _max_heap.top().first;
        }
        return answ;
    }
};
struct TEST{
    vector<int> nums;
    int k;
};
const vector<TEST> _testcases = {
    {
        {1,1,1,2,2,3},
        2,
    },
    {
        {1},
        1,
    },
    {
        {1,1,1,1,1,},
        1,
    },
    {
        {1,1,2,2,3,3,},
        2,
    },
    {
        {-1, -1},
        1,
    }
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        dzCommon::printArray(solve.topKFrequent(test.nums, test.k));
    }
    return 0;
}