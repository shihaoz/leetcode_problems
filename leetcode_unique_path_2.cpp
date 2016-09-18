//
//  leetcode_unique_path_2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_unique_path_2.hpp"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int len1 = obstacleGrid.size();
        if (len1 == 0) {
            return 0;
        }
        int len2 = obstacleGrid[0].size();
        if (len2 == 0 or obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        for (int i = 0; i < len1; i++) {
            if (obstacleGrid[i][0] == 1) {
                while (i < len1) {
                    obstacleGrid[i++][0] = 0;
                }
            }
            else{
                obstacleGrid[i][0] = 1;
            }
        }
        if (len2 > 1) {
            for (int i = 1; i < len2; i++) {
                if (obstacleGrid[0][i] == 1) {
                    while (i < len2) {
                        obstacleGrid[0][i++] = 0;
                    }
                }
                else{
                    obstacleGrid[0][i] = 1;
                }
            }
        }
        
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                }
                else{
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        dzCommon::printArrayArray(obstacleGrid);
        return obstacleGrid[len1-1][len2-1];
    }
};

const vector<vector<vector<int>>> _testcases = {
    {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    },
    {
        {1},
    },
    {
        {1,0,0},
        {0,0,0},
        {0,0,0},
    },
    {
        {0,1,0},
        {0,0,0},
        {0,0,0},
    },
};
int main(){
    Solution solve;
    
    for (auto matrix : _testcases) {
        cout << solve.uniquePathsWithObstacles(matrix) << "\n";
    }
    return 0;
}