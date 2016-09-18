//
//  leetcode_gas_station.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_gas_station.hpp"


class Solution {
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};

int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    if (gas.empty() or cost.empty()) {
        return 0;
    }
    // setup
    int start = 0, end = (1+start)%gas.size(), size = gas.size();
    int gas_total = gas[start], cost_total = cost[start];

    // find first start
    while (gas_total < cost_total) {
        start = (start-1+size) % size;
        if (start == 0) {
            return -1;
        }
        gas_total += gas[start];
        cost_total += cost[start];
    }

    while (end != start) {
        gas_total += gas[end];
        cost_total += cost[end];
        while (gas_total < cost_total) {
            start = (start-1+size) % size;
            if (start == 0 or start == end) {
                return -1;
            }
            gas_total += gas[start];
            cost_total += cost[start];
        }
        end = (end+1)%size;
    }
    return start;
}

struct TEST {
    vector<int> gas, cost;
};

const vector<TEST> _testcases = {
    {
        {99,98,97,100},
        {100,100,100,97}
    },
    {
        {99,98,100,100},
        {100,100,100,97}
    },
    {
        {101,98,98,100},
        {100,100,100,97}
    },
    {
        {5},
        {4}
    }
};

int main(){
    Solution solve;
    
    for (TEST test : _testcases) {
        cout << solve.canCompleteCircuit(test.gas, test.cost) << '\n';
    }
    return 0;
}