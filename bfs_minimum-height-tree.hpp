//
//  bfs_minimum-height-tree.hpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/23/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef bfs_minimum_height_tree_hpp
#define bfs_minimum_height_tree_hpp

#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class node {
public:
    int id;
    int max = -1;
    vector<int> children;
    int parent;
    node(int id){
        this->id = id;
    }
};

#endif /* bfs_minimum_height_tree_hpp */
