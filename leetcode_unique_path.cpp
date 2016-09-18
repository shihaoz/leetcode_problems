//
//  leetcode_unique_path.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_unique_path.hpp"

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 or n == 0) {
            return 0;
        }
        // setup
        vector<vector<int>> _states(m, vector<int>(n, 0));
        for (int i = 0; i < _states.size(); i++) {
            _states[i][0] = 1;
        }
        for (int i = 0; i < _states[0].size(); i++) {
            _states[0][i] = 1;
        }
        
        for (int i = 1; i < _states.size(); i++) {
            for (int j = 1; j < _states[i].size(); j++) {
                _states[i][j] += _states[i][j-1] + _states[i-1][j];
            }
        }
        return _states[m-1][n-1];
    }
};


const vector<pair<int, int>> _testcases = {
    {3, 7},
    {3, 3},
    {6, 6},
    {10, 1},
};

int main(){
    Solution solve;
    
    for (auto p : _testcases) {
        cout << solve.uniquePaths(p.first, p.second) << "\n";
    }
    return 0;
}