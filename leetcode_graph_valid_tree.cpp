//
//  leetcode_graph_valid_tree.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_graph_valid_tree.hpp"

class Solution {

public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<bool>> adjMatrix(n, vector<bool>(n, false));
        for (auto p : edges) {
            adjMatrix[p.first][p.second] = adjMatrix[p.second][p.first] = true;
        }
        unordered_set<int> visited;
        queue<int> _storage;
        _storage.push(0);   visited.insert(0);
        while (!_storage.empty()) {
            int now = _storage.front(); _storage.pop();
            for (int i = 0; i < adjMatrix[now].size(); i++) {
                if (adjMatrix[now][i]) {    // reachable
                    if (visited.find(i) != visited.end()) {
                        return false;   // cycle detected
                    }
                    visited.insert(i);  _storage.push(i);
                    adjMatrix[now][i] = adjMatrix[i][now] = false;
                }
            }
        }
        
        return visited.size() == n;
    }
};

struct TEST {
    int n;
    vector<pair<int, int>> edges;
};
const vector<TEST> _testcases = {
    {
        5,
        {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}},
    },
    {
        5,
        {{0, 1}, {2, 3},},
    },
    {
        5,
        {{0,1}, {1,2}, {1,3}, {4, 0}},
    },
    {
        2,
        {{0,1}},
    },
    {
        3,
        {{2,0}, {2,1}},
    },
    {
        4,
        {{2,3},{1,2},{1,3}},
    },
    {
        4,
        {{0,1}, {2,3}, {1,2}},
    }
};

int main(){
    Solution solve; cout << boolalpha;
    
    for (auto test : _testcases) {
        cout << solve.validTree(test.n, test.edges) << '\n';
    }
    return 0;
}