//
//  leetcode_paint_houses.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_paint_houses.hpp"

class Solution {
    
    int _minimumCost;
    /**
     at house idx, check available color, call recursively
     */
    void _recursion(int houseIdx, vector<vector<int>>& costMatrix, int costSoFar, int lastColor);
    const int INF = numeric_limits<int>::max();
public:
    int minCost1(vector<vector<int>>& costs) {
        _minimumCost = numeric_limits<int>::max();
        this->_recursion(0, costs, 0, -1);
        return _minimumCost;
    }
    int minCost2(vector<vector<int>>& costs){
        _minimumCost = 0;
        if (!costs.empty()) {
//            vector<int> nowCosts = {costs[0][0], costs[0][1], costs[0][2]},
//            nextCosts = {INF, INF, INF};
            for (int idx = 0; idx < costs.size()-1; idx++) {    // from 1 -> end
//                nextCosts[0] = min(nowCosts[1], nowCosts[2]) + costs[idx+1][0];
//                nextCosts[1] = min(nowCosts[0], nowCosts[2]) + costs[idx+1][1];
//                nextCosts[2] = min(nowCosts[0], nowCosts[1]) + costs[idx+1][2];
                costs[idx+1][0] += min(costs[idx][1], costs[idx][2]);
                costs[idx+1][1] += min(costs[idx][0], costs[idx][2]);
                costs[idx+1][2] += min(costs[idx][0], costs[idx][1]);
//                nowCosts = nextCosts;   nextCosts = {INF, INF, INF};
            }
            _minimumCost = min(min(costs.back()[0], costs.back()[1]), costs.back()[2]);
        }
        return _minimumCost;
    }
};

void Solution::_recursion(int houseIdx, vector<vector<int> > &costMatrix, int costSoFar, int lastColor){
    if (houseIdx == costMatrix.size()) {// end:
        _minimumCost = min(_minimumCost, costSoFar);
    }
    else{
        for (int i = 0 ; i < 3; i++) {
            if (lastColor != i) {
                this->_recursion(houseIdx+1, costMatrix, costSoFar + costMatrix[houseIdx][i], i);
            }
        }
    }
}

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
        {2, 1, 0},
        {3, 2, 3},
    },
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        cout << solve.minCost2(test) << '\n';
    }
    return 0;
}