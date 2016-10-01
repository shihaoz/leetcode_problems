//
//  ms_number_of_islands.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_number_of_islands.hpp"


class Solution {
    const char _LAND = '1';
    const char _WATER = '0';
    const vector<pair<int, int>> _check = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool _isLand(int x, int y, vector<vector<char>>& grid);
    void _helperDFS(vector<vector<char>>& grid, int x, int y);
public:
    int numIslands(vector<vector<char>>& grid) {
        int answ = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == this->_LAND) {
                    this->_helperDFS(grid, i, j);
                    answ++;
                }
            }
        }
        return answ;
    }
};

bool Solution::_isLand(int x, int y, vector<vector<char> > &grid){
    if (x >= 0 and y >= 0
        and
        x < grid.size() and y < grid[x].size()) {
        return grid[x][y] == this->_LAND;
    }
    return false;
}

void Solution::_helperDFS(vector<vector<char> > &grid, int x, int y){
    if (!this->_isLand(x, y, grid)) {   // not a land
        return;
    }
    grid[x][y] = this->_WATER;
    for (auto p : this->_check) {
        this->_helperDFS(grid, x+p.first, y+p.second);
    }
}

const vector<vector<vector<char>>> _testcases = {
    {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    },
    {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','1','1','0'},
    },
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'1','0','1','0','0'},
        {'0','0','0','1','1'},
    },
    {
        {'0'},
    },
    {
        {'1'},
    },
    {
        {'1', '1', '0', '1', '1'},
    }
};

int main(){
    Solution solve;
    for (auto matrix : _testcases) {
        cout << solve.numIslands(matrix) << "\n";
    }
    return 0;
}