//
//  leetcode_meeting_room.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/23/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_meeting_room.hpp"
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool cmp(Interval& a, Interval& b){
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return true;
        }
        // setup
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size()-1; i++) {
            if (intervals[i].end > intervals[i+1].start) {
                return false;
            }
        }
        return true;
    }
};

const vector<vector<Interval>> _testcases = {
    {
        {0,10},
    },
    {
        {0,30}, {5,10}, {15,20},
    },
    {
        {0,5}, {5,10}, {15,20},{20, 30},
    },
};

int main(){
    Solution solve; cout << boolalpha;
    for (auto vec : _testcases) {
        cout << solve.canAttendMeetings(vec) << "\n";
    }
    return 0;
}