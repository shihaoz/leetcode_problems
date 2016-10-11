//
//  fb_clone_graph.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_clone_graph.hpp"

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode*> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    void _DFS(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& mappings);
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode* node) {
        if (!node) {
            return nullptr;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mappings;
        this->_DFS(node, mappings);
        return mappings[node];
    }
};

void Solution::_DFS(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &mappings){
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    mappings[node] = newNode;
    for (int i = 0; i < node->neighbors.size(); i++) {
        if (mappings.find(node->neighbors[i]) == mappings.end()) {
            this->_DFS(node->neighbors[i], mappings);
        }
        newNode->neighbors.push_back(mappings[node->neighbors[i]]);
    }
    return;
}

