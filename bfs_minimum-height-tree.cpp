//
//  bfs_minimum-height-tree.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/23/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "bfs_minimum-height-tree.hpp"



/**
 * given # nodes + edges
 * return all roots of minimum-height-tree
 */
class Solution2 {
    int unreached = -1;
    int reach = 1;
public:
    static bool cmp(pair<int, int> left, pair<int, int> right){
        return left.first > right.first;
    }
    
    vector<vector<int>> grid;   // graph of edges
    vector<int> heights;    // dfs height of each node
    
    struct queue_info{
        int parent_longest; // longest from parent side, needed to +1 to be height
        int child;  // child id
        int parent; // parent id
        queue_info(int pl, int c, int p): parent_longest(pl), child(c), parent(p){
            
        }
    };
    
    void dfs(int src, vector<bool>& visited){
        heights[src] = 0;
        for (auto i : grid[src]) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i, visited);
                heights[src] = max(heights[i] + 1, heights[src]);
            }
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        grid = vector<vector<int>>(n);
        for (auto p : edges) {
            grid[p.first].push_back(p.second);
            grid[p.second].push_back(p.first);
        }
        
        heights = vector<int>(n, 0);
        
        // dfs
        int src = 0;
        vector<bool> visited(n, false);
        visited[src] = true;
        dfs(src, visited);
        
        
        // bfs to get answer
        vector<int> answ(n, 0);
        answ[src] = heights[src];
        queue<queue_info> nodes_queue;
        nodes_queue.push(queue_info(-1, src, -1));
        
        int min_height = numeric_limits<int>::max(); // minimum height so far
        vector<int> mhts;   // mht roots
        
        while ( !nodes_queue.empty() ) {
            auto now_info = nodes_queue.front();    nodes_queue.pop();
            int now = now_info.child;   int parent = now_info.parent;
            int parent_longest = now_info.parent_longest;
            
            // 1. find height
            pair<int, int> top1, top2;
            top1 = make_pair(parent_longest, parent);
            top2 = make_pair(-1, -1);
            for (auto i : grid[now]) {
                if (i != parent) {
                    if (heights[i] > top1.first) {
                        top2 = top1;
                        top1 = make_pair(heights[i], i);
                    }
                    else if(heights[i] > top2.first){
                        top2 = make_pair(heights[i], i);
                    }
                }
            }
            
            // 2. update its answ
            answ[now] = top1.first + 1;
            if (answ[now] < min_height) {
                mhts = vector<int>(1, now);
                min_height = answ[now];
            }
            else if (answ[now] == min_height){
                mhts.push_back(now);
            }
            
            // 3. assign to each child longest
            // trick: top1.first + 1 > min_height, no need to go down the child
            if (parent_longest + 1 > min_height) {
                continue;
            }
            int longest = 0;
            
            for (auto i : grid[now]) {
                if (i != parent) {
                    if (i != top1.second) {
                        longest = top1.first + 1;
                    }
                    else{
                        longest = top2.first + 1;
                    }
                    // the +1 means from that edge to now
                    nodes_queue.push(queue_info(longest, i, now));
                }
            }
        }
        
        return mhts;
    }
};


class Solution{
    
public:
    vector<int> answers;
    vector<int> longest_1st;
    vector<int> longest_2nd;
    
    struct queue_info{
        int parent;
        int child;
        int longest_parent;
        queue_info(int p, int c, int lp): parent(p), child(c), longest_parent(lp){
            
        }
    };
    
    void findHeight(int here, vector<bool>& visited, vector<vector<int>>& graph){
        longest_1st[here] = longest_2nd[here] = 0;

        for (int i : graph[here]) {
            if (!visited[i]) {
                visited[i] = true;
                
                findHeight(i, visited, graph);
                if (longest_1st[i]+1 > longest_1st[here]) {
                    longest_2nd[here] = longest_1st[here];
                    longest_1st[here] = longest_1st[i]+1;
                }
                else if(longest_1st[i] + 1 > longest_2nd[here]){
                    longest_2nd[here] = longest_1st[i]+1;
                }
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // 1. build graph
        vector<vector<int>> graph(n);
        for (auto p : edges) {
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
        }
        // 2. dfs, find largest/2nd largest height
        vector<bool> visited(n, false);
        visited[0] = true;
        longest_1st = longest_2nd = vector<int>(n, 0);
        findHeight(0, visited, graph);
        
        // 3. bfs each node
        int min_height = numeric_limits<int>::max();
        vector<queue_info> to_process;
        to_process.emplace_back(-1, 0, -1);
        
        int idx = 0;
        while (idx < to_process.size()) {
            queue_info holder = to_process[idx];
            
            // 3.1 get longest branch
            int longest_branch = max(holder.longest_parent+1, longest_1st[holder.child]);
            // 3.2 update min
            if (longest_branch < min_height) {
                min_height = longest_branch;
                answers = vector<int>(1, holder.child);
            }
            else if (longest_branch == min_height){
                answers.push_back(holder.child);
            }
            
            // 3.3 bfs to children
            for (int i : graph[holder.child]) {
                if (i != holder.parent) {
                    // this is a child
                    int child_longest = max(holder.longest_parent+1, (longest_1st[i] + 1 == longest_branch) ? longest_2nd[holder.child] : longest_1st[holder.child]);
                    to_process.emplace_back(holder.child, i, child_longest);
                }
            }
            idx++;
        }
        return answers;
    }
};

int main(){
    Solution now;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(1, 3));

    
    auto answ = now.findMinHeightTrees(edges.size()+1, edges);
    for (int i : answ) {
        cout << i << " ";
    }cout << "\n";
    
    edges.clear();
    
    edges.push_back(make_pair(0, 1));
    answ = now.findMinHeightTrees(edges.size()+1, edges);
    for (int i : answ) {
        cout << i << " ";
    }cout << "\n";
    
    edges.clear();
    
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(4, 5));
    
    answ = now.findMinHeightTrees(edges.size()+1, edges);
    for (int i : answ) {
        cout << i << " ";
    }cout << "\n";
    
    edges.clear();
    return 0;
}