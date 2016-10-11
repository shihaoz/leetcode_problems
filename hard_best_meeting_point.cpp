//
//  hard_best_meeting_point.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/8/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "hard_best_meeting_point.hpp"

class Solution {
public:
    int getBestRow(vector<vector<int>>& grid, int numHome);
    int getBestColumn(vector<vector<int>>& grid, int numHome);
    
    int minTotalDistance(vector<vector<int>>& grid) {
        int result = 0;
        vector<pair<int, int>> homes;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    homes.push_back({i,j});
                }
            }
        }
        // for 1-dimention, the coord is at X where you cannot improve by going to X-1 or X+1
        int row = getBestRow(grid, homes.size()), col = getBestColumn(grid, homes.size());
        for (auto p : homes) {
            result += abs(p.first - row) + abs(p.second - col);
        }
        return result;
    }
};


int Solution::getBestRow(vector<vector<int> > &grid, int numHome){
    int leftAmount = 0, rightAmount = numHome;
    int bestIdx = 0;
    while (bestIdx < grid.size()) {
        int onTheRow = 0;
        for (int i = 0; i < grid[bestIdx].size(); i++) {
            onTheRow += (grid[bestIdx][i] == 1);
        }
        leftAmount += onTheRow; rightAmount -= onTheRow;
        // by going one row up, the added cost is: leftAmount - rightAmount
        int addedCost = leftAmount - rightAmount;
        if (addedCost >= 0) {   // no improvement can be achieved
            break;
        }
        bestIdx++;
    }
    return bestIdx;
}
int Solution::getBestColumn(vector<vector<int>>& grid, int numHome){
    int leftAmount = 0, rightAmount = numHome;
    int bestIdx = 0, colSize = grid[0].size();
    while (bestIdx < colSize) {
        int onTheRow = 0;
        for (int i = 0; i < grid.size(); i++) {
            onTheRow += (grid[i][bestIdx] == 1);
        }
        leftAmount += onTheRow; rightAmount -= onTheRow;
        // by going one col right, the added cost is: leftAmount - rightAmount
        int addedCost = leftAmount - rightAmount;
        if (addedCost >= 0) {   // no improvement can be achieved
            break;
        }
        bestIdx++;
    }
    return bestIdx;
}
const vector<vector<vector<int>>> _testcases = {
    {
        {1,0,0,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0},
    },
    {
        {1,0,0,0,1},
    },
    {
        {1,0,1,1,0,0,1},
        {1,0,0,0,0,0,1},
        {0,1,0,1,0,1,0},
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.minTotalDistance(test) << '\n';
    }
    return 0;
}