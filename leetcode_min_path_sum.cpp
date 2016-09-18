//
//  leetcode_min_path_sum.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_min_path_sum.hpp"


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        // setup
//        vector<vector<int>> _states(grid.size(),
//                                    vector<int>(grid.front().size(), numeric_limits<int>::max()));
//        _states[0][0] = grid[0][0];
//        
//        for (int i = 0; i < _states.size(); i++) {
//            for (int j = 0; j < _states[i].size(); j++) {
//                if (i+1 < _states.size()) {
//                    _states[i+1][j] = min(_states[i+1][j], _states[i][j] + grid[i+1][j]);
//                }
//                if (j+1 < _states[i].size()) {
//                    _states[i][j+1] = min(_states[i][j+1], _states[i][j] + grid[i][j+1]);
//                }
//            }
//        }
//        return _states.back().back();
        
        // setup
        for (int i = 1; i < grid[0].size(); i++) {
            grid[0][i] += grid[0][i-1];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int min_local = numeric_limits<int>::max();
                if (i-1 >= 0) {
                    min_local = grid[i-1][j] + grid[i][j];
                }
                if (j-1 >= 0) {
                    min_local = min(min_local, grid[i][j-1] + grid[i][j]);
                }
                grid[i][j] = min_local;
            }
        }
        return grid.back().back();
    }
};
const vector<vector<vector<int>>> _testcases = {
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    },
    {
        {1},
    },
    {
        {3, 6, 0},
        {4, 3, 1},
    }
};
int main(){
    Solution solve;
    
    for (auto matrix : _testcases) {
        cout << solve.minPathSum(matrix) << "\n";
    }
    return 0;
}