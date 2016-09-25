//
//  leetcode_insert_Interval.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/24/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_insert_Interval.hpp"
using namespace dzInterval;
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            return vector<Interval>(1, newInterval);
        }
        
        vector<Interval> _answ;
        // find first one
        int idx = 0, to_insert = intervals.size();
        while (idx < intervals.size()) {
            if (intervals[idx].end >= newInterval.start) {
                to_insert = min(idx, to_insert);
                // non overlap
                if (newInterval.end >= intervals[idx].start) {
                    // overlap
                    newInterval.start = min(newInterval.start, intervals[idx].start);
                    newInterval.end = max(newInterval.end, intervals[idx].end);
                }
                else{
                    _answ.push_back(intervals[idx]);
                }
            }
            else{
                _answ.push_back(intervals[idx]);
            }
            idx++;
        }
        _answ.insert(_answ.begin() + to_insert, newInterval);
        return _answ;
    }
};
struct TEST {
    vector<Interval> inputs;
    Interval newInterval;
};
const vector<TEST> _testcases = {
    {
        {{1,3},{6,9}},
        {2,5}
    },
    {
        {{1,2},{3,5}, {6,7}, {8,10}, {12,16}},
        {4,9},
    },
    {
        {},
        {1,5},
    },
    {
        {{0, 9}},
        {1,5},
    },
    {
        {{1,2}, {8,9}},
        {4,5},
    },
    {
        {{1,2}, {8,9}},
        {13,15},
    },
};


int main(){
    Solution solve;
    for (auto test : _testcases) {
        printIntervalArray(solve.insert(test.inputs, test.newInterval));
    }
    return 0;
}