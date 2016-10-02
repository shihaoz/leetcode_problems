//
//  leetcode_number_connected_components.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_number_connected_components.hpp"


class Solution {

public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int count = n;

        /// union find
        vector<int> heads(n);   iota(heads.begin(), heads.end(), 0);
        
        for (int i = 0; i < edges.size(); i++) {
            int smaller = edges[i].first, larger = edges[i].second;
            while (heads[smaller] != smaller) {smaller = heads[smaller];}   // find head of left
            while (heads[larger] != larger) {larger = heads[larger];}   // find head of right
            if (smaller != larger) {    // same head
                if (smaller > larger) {swap(smaller, larger);}
                heads[larger] = heads[smaller];
                count--;
            }
        }
        
        return count;
    }
};

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
        5,
        {},
    },
    {
        5,
        {{0,1},{2,3}},
    },
    {
        5,
        {{0,1},{1,2},{0,2},{3,4}},
    },
};
int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.countComponents(test.n, test.edges) << '\n';
    }
    return 0;
}