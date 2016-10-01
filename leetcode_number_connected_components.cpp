//
//  leetcode_number_connected_components.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_number_connected_components.hpp"


class Solution {
    void _helper(int x, vector<list<int>>& adjList, vector<bool>& visited);
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int count = 0;

        vector<list<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++) {    // construct adj list
            adjList[edges[i].first].push_back(edges[i].second);
            adjList[edges[i].second].push_back(edges[i].first);
        }
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {// unvisited node
                this->_helper(i, adjList, visited);
                count++;
            }
        }
        return count;
    }
};

void Solution::_helper(int x, vector<list<int>>& adjList, vector<bool>& visited){
    visited[x] = true;
    queue<int> _storage;    _storage.push(x);
    while (!_storage.empty()) {
        int now = _storage.front(), node;
        _storage.pop();
        
        while (!adjList[now].empty()) {
            node = adjList[now].front();    adjList[now].pop_front();
            if (!visited[node]) {
                _storage.push(node);
                visited[node] = true;
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
    },
};
int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.countComponents(test.n, test.edges) << '\n';
    }
    return 0;
}