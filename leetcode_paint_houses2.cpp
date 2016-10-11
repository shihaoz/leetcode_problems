//
//  leetcode_paint_houses2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_paint_houses2.hpp"

class Solution {
    int _minCost;
public:
    int minCostII(vector<vector<int>>& costs) {
        _minCost = 0;
        if (!costs.empty()) {
            for (int houseIdx = 0; houseIdx < costs.size()-1; houseIdx++) {
                int smallest = numeric_limits<int>::max(), idx = -1, small2 = numeric_limits<int>::max();
                for (int i = 0; i < costs[houseIdx].size(); i++) {
                    if (costs[houseIdx][i] < smallest) {
                        small2 = smallest;
                        smallest = costs[houseIdx][i]; idx = i;
                    }
                    else if(costs[houseIdx][i] < small2){
                        small2 = costs[houseIdx][i];
                    }
                }
                for (int i = 0; i < costs[houseIdx+1].size(); i++) {/// update next houses
                    if (idx != i) {
                        costs[houseIdx+1][i] += smallest;
                    }
                    else {
                        costs[houseIdx+1][i] += small2;
                    }
                }
            }
            _minCost = *min_element(costs.back().begin(), costs.back().end());
        }
        return _minCost;
    }
};

const vector<vector<vector<int>>> _testcases = {
    {
        {3,4,5},
        {4,5,4},
        {5,3,3},
    },
    {
        {2,1,0},
    },
    {
        {2, 1, 0, 4},
        {3, 2, 3, 1},
    },
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        cout << solve.minCostII(test) << '\n';
    }
    return 0;
}