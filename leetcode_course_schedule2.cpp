//
//  leetcode_course_schedule2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/2/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_course_schedule2.hpp"

class Solution {
    int _assignIdx;
    vector<int> answ;
    bool DFS(int node, vector<list<int>> &adjList, unordered_set<int> &visited, vector<bool> &indexes);
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        this->_assignIdx = numCourses-1;
        answ = vector<int>(numCourses);
        vector<bool> indexes(numCourses, false);
        vector<list<int>> adjList(numCourses);
        for (auto p : prerequisites) {
            adjList[p.second].push_back(p.first);
        }
        unordered_set<int> visited;
        for (int i = 0; i < numCourses; i++) {
            if(!this->DFS(i, adjList, visited, indexes)){
                return {};
            }
            visited.clear();
        }
        return answ;
    }
    vector<int> findOrderTopoSort(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<int> answ;
        
        vector<int> inDegree(numCourses, 0);    // build in-degree
        vector<list<int>> adjList(numCourses);  // build adjList [src] = det
        for (auto p : prerequisites) {
            adjList[p.second].push_back(p.first);
            inDegree[p.first]++;
        }


        queue<int> _next;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) { // store all in-degree == 0
                _next.push(i);
            }
        }
        while (!_next.empty()) {
            int now = _next.front();    _next.pop();
            answ.push_back(now);
            for (auto it = adjList[now].begin(); it != adjList[now].end(); it++) {
                inDegree[*it]--;
                if (inDegree[*it] == 0) {
                    _next.push(*it);
                }
            }
        }
        if (answ.size() < numCourses) {
            return {};
        }
        return answ;
    }
};

bool Solution::DFS(int node, vector<list<int>> &adjList, unordered_set<int> &visited, vector<bool> &indexes){
    if (visited.find(node) != visited.end()) {  // cycle detected
        return false;
    }
    if (indexes[node]) {    // if this node is visited before
        return true;
    }
    visited.insert(node);
    for (auto it = adjList[node].begin(); it != adjList[node].end(); it++) {
        if (!this->DFS(*it, adjList, visited, indexes)) {
            return false;
        }
    }
    visited.erase(node);
    this->answ[this->_assignIdx--] = node;
    indexes[node] = true;
    return true;
}


struct TEST {
    int numCourses;
    vector<pair<int, int>> prerequisites;
};
const vector<TEST> _testcases = {
//    {
//        2,
//        {{1,0}, {0,1}},
//    },
    {
        4,
        {{1,0}, {2, 0}, {1, 2}},
    },
    {
        1,
        {},
    },
    {
        4,
        {{1,0}, {3,2}, {1,3}, {2, 0}},
    },
    {
        3,
        {{1, 0}, {0, 2}, {2, 1}},
    },
    {
        4,
        {{1,0}, {2,0}, {3,1}, {3,2}},
    },
};


int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        dzCommon::printArray(solve.findOrderTopoSort(test.numCourses, test.prerequisites), true);
    }
    return 0;
}