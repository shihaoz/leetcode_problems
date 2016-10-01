//
//  leetcode_number_connected_components.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_number_connected_components.hpp"


class Solution {
    void _helper(int x, vector<vector<int> > &adjMatrix);
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int count = 0;
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
        for (auto p : edges) {
            adjMatrix[p.first][p.second] = adjMatrix[p.second][p.first] = 1;
        }
        for (int i = 0; i < n; i++) {   // self-link
            adjMatrix[i][i] = 1;
        }
        
        for (int i = 0; i < adjMatrix.size(); i++) {
            for (int j = 0; j < adjMatrix[i].size(); j++) {
                if (adjMatrix[i][j]) {
                    this->_helper(i, adjMatrix);
                    count++;
                }
            }
        }
        return count;
    }
};

void Solution::_helper(int x, vector<vector<int> > &adjMatrix){
    
    queue<int> _storage;    _storage.push(x);
    int now;
    while (!_storage.empty()) {// not empty, get all connect node
        now = _storage.front(); _storage.pop();
        adjMatrix[now][now] = 0;
        for (int i = 0; i < adjMatrix[now].size(); i++) {
            if (adjMatrix[now][i]) {    // if connected and unvisited
                /// push to storage, and mark visited
                _storage.push(i);
                adjMatrix[now][i] = adjMatrix[i][now] = 0;
            }
        }
    }
}
struct TEST {
    int n;
    vector<pair<int, int>> edges;
};

const vector<TEST> _testcases = {
    {
        5,
        {{0,1},{1,2},{3,4}},
    },
    {
        5,
        {{0,1},{1,2},{2,3},{3,4}},
    },
    {
        2000,
        {},
    },
    {
        5,
        {{0,1},{2,3}},
    }
};
int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.countComponents(test.n, test.edges) << '\n';
    }
    return 0;
}