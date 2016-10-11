//
//  hard_shortest_all_building.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/9/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "hard_shortest_all_building.hpp"

class Solution {
    /**
     @input: grid, result matrix <# reaches here, costs>, starting coordinate
     @return:
        update the result matrix
     */
    int _BFS(vector<vector<int>>& grid, vector<vector<pair<int, int>>>& result, int x, int y);
    const vector<pair<int, int>> _changes = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    /**
     @input grid, coordinate
     @return:
        if x,y are valid, and [x][y] is empty land
     */
    bool _ifValid(vector<vector<int>>& grid, int x, int y);
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int minDistance = numeric_limits<int>::max();
        int numBuildings = 0;
        /// for each building, do BFS
        vector<vector<pair<int, int>>> result(grid.size(),
                                              vector<pair<int, int>>(grid.front().size(), {0,0}));
        /// count total number of home
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                numBuildings += (grid[i][j] == 1);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    if(this->_BFS(grid, result, i, j) < numBuildings){
                        return -1;      // a building cannot reach everyone else
                    }
                }
            }
        }
        /// each point that can be the meeting point, select best
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                if (grid[i][j] == 0 and result[i][j].first == numBuildings) {
                    minDistance = min(minDistance, result[i][j].second);
                }
            }
        }

        return (minDistance == numeric_limits<int>::max()) ? -1 : minDistance;
    }
};
bool Solution::_ifValid(vector<vector<int> > &grid, int x, int y){
    return x >= 0 and y >= 0 and x < grid.size() and y < grid[x].size();
}

int Solution::_BFS(vector<vector<int> > &grid, vector<vector<pair<int, int> > > &result,
                    int x, int y){
    vector<vector<bool>> reached(grid.size(), vector<bool>(grid.front().size(), false));
    reached[x][y] = true;
    queue<pair<int, int>> next; next.push({x,y});
    int steps = 0, size_now = next.size(), size_next = 0, homeSeen = (grid[x][y] == 1);
    int nowX, nowY;
    while (!next.empty()) {
        tie(nowX, nowY) = next.front();    next.pop();  size_now--;
        result[nowX][nowY].first += 1;
        result[nowX][nowY].second += steps;
        for (auto change : _changes) {
            int newX = nowX + change.first, newY = nowY + change.second;
            if (_ifValid(grid, newX, newY) and !reached[newX][newY]) {
                reached[newX][newY] = true;
                homeSeen += (grid[newX][newY] == 1);    // record number of home seen
                if (grid[newX][newY] == 0) {
                    next.push({newX, newY});    size_next++;
                    
                }
            }
        }
        if (size_now == 0) {
            swap(size_now, size_next);  steps++;
        }
    }
    return homeSeen;
}

const vector<vector<vector<int>>> _testcases = {
    {
        {1, 0, 2, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
    },
    {
        {1, 0, 0},
        {1, 0, 0},
        {0, 0, 1},
    },
    {
        {1, 0, 0},
    },
    {
        {1, 2, 0},
    },
    {
        {1, 2, 0},
        {1, 2, 0},
        {2, 1, 1},
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.shortestDistance(test) << '\n';
    }
    return 0;
}