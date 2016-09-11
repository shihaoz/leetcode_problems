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
    
    void pushStartPoints(map<int, int, greater<int>>& cont, vector<int>& heights, int idx, vector<pair<int, int>>& answ);
    void pushEndPoints(map<int, int, greater<int>>& cont, vector<int>& heights, int idx, vector<pair<int, int>>& answ);
    vector<pair<int, int>> getSkyline(vector<vector<int>>& inputs) {
        vector<pair<int, int>> answ;
        map<int, vector<int>> _start, _end; // <idx, [height] >
        map<int, int, greater<int>> cont;   // <height, count >
        // store into start points and end points
        for (auto& vec : inputs) {
            _start[vec[0]].push_back(vec[2]);
            _end[vec[1]].push_back(vec[2]);
        }
        auto it_start = _start.begin(), it_end = _end.begin();
        while (it_start != _start.end() and it_end != _end.end()) {
            if (it_start->first < it_end->first) {
                // push in start
                this->pushStartPoints(cont, it_start->second, it_start->first, answ);
                it_start++;
            }
            else if (it_start->first == it_end->first){
                // push in start
                this->pushStartPoints(cont, it_start->second, it_start->first, answ);
                // push in end
                this->pushEndPoints(cont, it_end->second, it_end->first, answ);
                it_start++; it_end++;
            }
            else{
                // push in end
                this->pushEndPoints(cont, it_end->second, it_end->first, answ);
                it_end++;
            }
        }
        while (it_start != _start.end()) {
            this->pushStartPoints(cont, it_start->second, it_start->first, answ);
            it_start++;
        }
        while (it_end != _end.end()) {
            this->pushEndPoints(cont, it_end->second, it_end->first, answ);
            it_end++;
        }
        
        return answ;
    }
};


void Solution::pushStartPoints(map<int, int, greater<int>> &cont, vector<int> &heights, int idx, vector<pair<int, int>> &answ){
    for (int h : heights) {
        int top_height = (cont.empty()) ? 0 : cont.begin()->first;
        if (top_height >= h) {
            // do nothing
        }
        else{
            if (answ.empty() or
                answ.back().first < idx) {
                answ.push_back(make_pair(idx, h));
            }
            else if(answ.back().first == idx and answ.back().second < h){
                // higher the better
                answ.back().second = h;
            }
        }
        cont[h] += 1;   // count the heights
    }
}
void Solution::pushEndPoints(map<int, int, greater<int>> &cont, vector<int> &heights, int idx, vector<pair<int, int>> &answ){
    for (int h : heights) {
        cont[h]--;
        if (cont[h] == 0) {
            cont.erase(h);
        }
        int top_height = (cont.empty()) ? 0 : cont.begin()->first;
        if (top_height >= h) {
            // do nothing
        }
        else{
            if (answ.empty() or
                answ.back().first < idx) {
                answ.push_back(make_pair(idx, top_height));
            }
            else if(answ.back().first == idx and answ.back().second > top_height){
                // lower the better (since this is an end)
                answ.back().second = top_height;
            }
        }
    }
}

vector<vector<vector<int>>> _testcases = {
    {
        {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}
    },
    {
        {1, 3, 10}, {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8},
    },
    {
        {0, 2, 3}, {2, 5, 3}
    },
    {
        {1, 2, 1}, {1, 2, 2}, {1, 2, 3},
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
        printArray(solve.getSkyline(test));
    }
    return 0;
}

