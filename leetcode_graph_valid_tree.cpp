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
        vector<int> heads(n);   iota(heads.begin(), heads.end(), 0);
        int count = n;
        for (auto edge : edges) {
            int head1, head2;   tie(head1, head2) = edge;
            while (heads[head1] != head1) {head1 = heads[head1];}
            while (heads[head2] != head2) {head2 = heads[head2];}
            if (head1 == head2) {
                return false;
            }
            int smaller = min(head1, head2), larger = max(head1, head2);
            heads[larger] = smaller;
            count--;
        }
        return count == 1;
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