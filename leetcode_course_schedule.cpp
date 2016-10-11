//
//  leetcode_course_schedule.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_course_schedule.hpp"

class Solution {
    bool DFS(unordered_set<int>& visited, vector<list<int>>& edges, int node);
public:
    /**
     method 1:
        create a graph (adjacency list), detect cycle
     
     */
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        /**
         use DFS cycle detection
         */
        vector<list<int>> edges(numCourses);
        for (auto p : prerequisites) {
            edges[p.second].push_back(p.first);
        }
        for (int i = 0; i < numCourses; i++) {
            unordered_set<int> visited;
            if (!this->DFS(visited, edges, i)) {
                return false;
            }
        }
        return true;
    }
    bool canFinishTopoSort(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<int> answ;   answ.reserve(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<list<int>> adjList(numCourses);
        for (auto p : prerequisites) {
            adjList[p.second].push_back(p.first);
            inDegree[p.first]++;
        }
        queue<int> _next;
        for (int i = 0; i < inDegree.size(); i++) {// store all in-Degree == 0
            if (inDegree[i] == 0) {
                _next.push(i);
            }
        }
        while (!_next.empty()) {
            int now = _next.front();    _next.pop();
            answ.push_back(now);
            for (auto it = adjList[now].begin(); it != adjList[now].end(); it++) {
                inDegree[*it]--;
                if (inDegree[*it] == 0) {// store in-Degree == 0
                    _next.push(*it);
                }
            }
        }
        return answ.size() == numCourses;
    }
};

bool Solution::DFS(unordered_set<int> &visited, vector<list<int> > &edges, int node){
    if (visited.find(node) != visited.end()) {
        return false;
    }
    visited.insert(node);
    auto it = edges[node].begin();
    while (it != edges[node].end()) {
        if (!this->DFS(visited, edges, *it)) {
            return false;
        }it++;
    }
    edges[node].clear();    // after checking
    visited.erase(node);
    return true;
}


struct TEST {
    int numCourses;
    vector<pair<int, int>> prerequisites;
};
const vector<TEST> _testcases = {
    {
        2,
        {{1,0}, {0,1}},
    },
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
};

int main(){
    Solution solve; cout << boolalpha;
    
    for (auto test : _testcases) {
        cout << solve.canFinishTopoSort(test.numCourses, test.prerequisites) << "\n";
    }
    return 0;
}