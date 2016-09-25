//
//  leetcode_meetingroom2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/23/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_meetingroom2.hpp"
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
struct checkPoint{
    int diff;
    checkPoint(): diff(0){}
};
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        int max_room = -1, rooms = 0;
        // build sorted array
        map<int, checkPoint> points;
        for (Interval & i : intervals) {
            points[i.start].diff++;
            points[i.end].diff--;
        }
        for (auto it = points.begin(); it != points.end(); it++) {
            rooms += it->second.diff;
            max_room = max(max_room, rooms);
        }
        return max_room;
    }
};
const vector<vector<Interval>> _testcases = {
    {
        {0, 30}, {5, 10}, {15, 20}
    },
    {
        {0, 30}, {5, 10}, {10, 20}, {0, 40}
    },
    {
        {0, 1},
    },
    {
        {1,2}, {2, 3}, {3, 6}, {4, 5}, {5, 10},
    }
};

int main(){
    Solution solve;
    
    for (auto vec : _testcases) {
        cout << solve.minMeetingRooms(vec) << "\n";
    }
    return 0;
}