
//
//  leetcode_merge_intervals.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_merge_intervals.hpp"



struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    static bool _cmpByFirst(Interval a, Interval b){
        return ((a.start != b.start) ? a.start < b.start : a.end < b.end);
    }
public:
    vector<Interval> merge_nlogn(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        vector<Interval> answ;
        // sort
        sort(intervals.begin(), intervals.end(), this->_cmpByFirst);
        
        int left = intervals.front().start, right = intervals.front().end;
        for (auto& here : intervals) {
            if (here.start > right) {
                answ.emplace_back(left, right);
                left = here.start;
            }
            right = max(right, here.end);
        }
        answ.emplace_back(left, right);
        return answ;
    }

};

const vector<vector<Interval>> _testcases = {
    {{1,3}, {2,6}, {8, 10}, {15,18}},    // {{1,6}, {8,10}, {15, 18}}
    {{1,3}, {2,6}, {6, 10}, {15,18}},    // {{1,10}, {15, 18}}
    {{1,5}},                             // {1,5}
    {{0, 5}, {0, 8}, {0, 10}},           // {{0, 10}}
};
void printArray(vector<Interval> vec){
    for (auto& in : vec) {
        cout << "(" << in.start << ", " << in.end << ") ->";
    }cout << "\n";
}
int main(){
    Solution solve;
    
    for (auto vec : _testcases) {
        printArray(solve.merge_nlogn(vec));
    }
    return 0;
}