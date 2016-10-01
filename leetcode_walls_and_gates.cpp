//
//  leetcode_walls_and_gates.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_walls_and_gates.hpp"
const int INF = 2147483647;
class Solution {
    const int _WALL = -1;
    const int _GATE = 0;
    const int _EMPTY_ROOM = numeric_limits<int>::max();
    bool _valid(int x, int y, vector<vector<int>>& rooms);
    const vector<pair<int, int>> _steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void _dfs(vector<vector<int>>& rooms, int x, int y, int steps);
    void _bfs(vector<vector<int>>& rooms, int x, int y);
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == this->_GATE) {
//                    for (auto step : this->_steps) {    // traverse each room
//                        this->_dfs(rooms, i + step.first, j + step.second, 1);
//                    }
                    this->_bfs(rooms, i, j);
                }
            }
        }
    }
};

bool Solution::_valid(int x, int y, vector<vector<int> > &rooms){
    if (x >= 0 and y >= 0
        and
        x < rooms.size() and y < rooms[x].size()
        and
        rooms[x][y] > this->_GATE and rooms[x][y] <= this->_EMPTY_ROOM) {
        return true;
    }
    return false;
}
void Solution::_dfs(vector<vector<int> > &rooms, int x, int y, int steps){
    if (this->_valid(x, y, rooms)
        and
        steps <= rooms[x][y]) {
        /// this is a room that can be updated
        rooms[x][y] = steps;
        for (auto step : this->_steps) {    // traverse each room
            this->_dfs(rooms, x + step.first, y + step.second, steps+1);
        }
    }
}

void Solution::_bfs(vector<vector<int> > &rooms, int x, int y){
    /// x,y is a gate, starts here
    queue<pair<int, int>> _nexts;
    for (auto p : this->_steps) {
        _nexts.push({x + p.first, y + p.second});
    }
    int size = _nexts.size(), size_next = 0;
    int step = 1;   // steps to closest gates
    int x_now, y_now;
    while (size > 0) {
        
        tie(x_now, y_now) = _nexts.front();
        _nexts.pop();   size--;
        if (this->_valid(x_now, y_now, rooms)   // valid
            and
            step < rooms[x_now][y_now]  // can be improved
            ) {
            rooms[x_now][y_now] = step; // update
            for (auto p : this->_steps) {
                _nexts.push({x_now + p.first, y_now + p.second});
            }
            size_next += 4;
        }
        if (size == 0) {// this level is finished
            swap(size, size_next);
            step ++;
        }
    }
    return;
}

const vector<vector<vector<int>>> _testcases = {
    {
        {INF,  -1,  0,  INF},
        {INF, INF, INF, -1},
        {INF, -1, INF,  -1},
        {0, -1, INF, INF},
    },
    {
        {INF,  -1,  0,  INF},
        {INF, 0, INF, -1},
        {INF, -1, -1,  -1},
        {0, -1, INF, INF},
    },
    {
        {INF},
    },
    {
        {-1, 0,},
        {INF, -1},
    },
};

int main(){
    Solution solve;
    
    for (auto matrix : _testcases) {
        solve.wallsAndGates(matrix);
        dzCommon::printArrayArray(matrix, true);
    }
    return 0;
}