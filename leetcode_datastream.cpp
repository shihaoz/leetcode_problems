//
//  leetcode_datastream.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/13/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_datastream.hpp"


struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
    map<int, int> _intervals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        // empty, insert new interval
        if (_intervals.empty()) {
            _intervals[val] = val;
        }
        else{
            auto right = _intervals.lower_bound(val), left = right;
            bool in_left = false, in_right = false,
            merge_left = false, merge_right = false;
            /// check if new val is already in intervals, or next to
            if (left != _intervals.begin()) {
                --left;
                in_left = (left->second >= val);
                merge_left = (left->second == val - 1);
            }
            if (right != _intervals.end()) {
                in_right = (right->first <= val);
                merge_right = (right->first == val + 1);
            }
            /// if not in any, check merge
            if (merge_left and merge_right) {
                left->second = right->second;
                _intervals.erase(right);
            }
            else if (merge_left){
                left->second = val;
            }
            else if (merge_right){
                _intervals[val] = right->second;
                _intervals.erase(right);
            }
            else{
                if (!in_left and !in_right) {
                    // create new
                    _intervals[val] = val;
                }
            }
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> answ;
        for (auto it = _intervals.begin(); it != _intervals.end(); it++) {
            answ.emplace_back(it->first, it->second);
        }
        return answ;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
void printInterval(vector<Interval> vec){
    for (auto& in : vec) {
        cout << "(" << in.start << ", " << in.end << ") ";
    }cout << "\n";
}
const vector<vector<int>> _testcases = {
    {
        1, 3, 7, 2, 6,
    },
    {
        1, 5, 3, 2, 4,
    },
    {
        -1, 0
    },
    {
        6, 6, 0, 4, 8, 7, 6, 4, 7, 5
    }
};

int main(){
    for (auto& test : _testcases) {
        SummaryRanges sum;
        for (int i : test) {
            sum.addNum(i);
            printInterval(sum.getIntervals());
        }
        cout << "******\n";
    }
    return 0;
}