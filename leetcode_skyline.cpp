//
//  leetcode_skyline.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/8/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_skyline.hpp"

bool cmp(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}
class Solution {
    
public:
    vector<pair<int, int>> getSkyline_n2(vector<vector<int>>& buildings) {
        vector<pair<int, int>> answ;  // <x, h>
        answ.emplace_back(0,0);
        // 1. sort by height
        sort(buildings.begin(), buildings.end(), cmp);
        
        // 2. for each building
        for (vector<int>& next : buildings) {
            int x = next[0], y = next[1], h = next[2];
            int x_idx = 0, y_idx = 0;
            pair<int, int> insert_x(-1, -1), insert_y(-1, -1);
            // find x find y
            for (x_idx = 0; x_idx < answ.size() and answ[x_idx].first < x; x_idx++) {}
            for (y_idx = x_idx; y_idx < answ.size() and answ[y_idx].first <= y; y_idx++) {}
            if (answ[--x_idx].second < h) {
                insert_x = make_pair(x, h);
            }
            if (answ[--y_idx].second < h) {
                insert_y = make_pair(y, answ[y_idx].second);
            }
            x_idx++;    // point to where x will be
            y_idx++;    // point to where y will be (before x is inserted)
            int remove_start, remove_end;
            if (insert_x.first != -1) {
                answ.insert(answ.begin() + x_idx, insert_x);
                y_idx++;    // increment y_idx after x is inserted
                remove_start = x_idx+1;
            }
            else{
                remove_start = x_idx;
            }
            if (insert_y.first != -1) {
                answ.insert(answ.begin() + y_idx, insert_y);
            }
            remove_end = y_idx;
            answ.erase(answ.begin() + remove_start, answ.begin() + remove_end);
        }
        return (answ.front() == make_pair(0, 0)) ?
            vector<pair<int, int>>(answ.begin()+1, answ.end())
                : answ;
    }
    
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> answ;
        map<int, priority_queue<pair<int, int>>> start, end;  // left/right->[<height, idx>]
        for (int i = 0; i < buildings.size(); i++) {
            start[buildings[i][0]].push(make_pair(buildings[i][2], i));
            end[buildings[i][1]].push(make_pair(buildings[i][2], i));
        }
        
        map<int, int> cont; // <height, count>
        
        auto it_start = start.begin(), it_end = end.begin();
        while (it_start != start.end() and it_end != end.end()) {
            if (it_start->first < it_end->first) {
                while (!it_start->second.empty()) {
                    pair<int, int> now = it_start->second.top();    it_start->second.pop();
                    
                }
            }
            if (it_end->first <= it_start->first) {
                
            }
        }
        return answ;
    }
};
vector<vector<vector<int>>> _testcases = {
    {
        {1, 3, 10}, {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8},
    },
    {
        {0, 2, 3}, {2, 5, 3}
    }
};
void printArray(vector<pair<int, int>> vec){
    for (auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }cout << "\n";
}
int main(){
    Solution solve;
    
    for (auto& test : _testcases) {
        printArray(solve.getSkyline_n2(test));
    }
    return 0;
}

