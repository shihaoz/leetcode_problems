//
//  leetcode_number_islands.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/28/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_number_islands.hpp"


class Solution {
    const char _land = '1', _water = '0';
public:
    int _X, _Y;
    
    void visit(vector<vector<char>>& grid, pair<int, int>& now){
        grid[now.first][now.second] = _water;
    }
    bool checkValid(int x, int y){
        return x >= 0 and y >= 0
        and x < _X and y < _Y;
    }
    
    void addToQueue(vector<vector<char>>& grid, queue<pair<int, int>>& q, int left, int right){
        q.push(make_pair(left, right));
        grid[left][right] = _water;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() or grid[0].empty()) {
            return 0;
        }
        _X = grid.size();
        _Y = grid[0].size();

        /** setup
         * seed is the next land to explore
         * we keep track of count of land_visited, and land_total
         * and use bfs to traverse the map.
         */
        
        int answ = 0;
        pair<int, int> seed(0, 0);  // bug-fix: seed must be a land to be added in queue
        queue<pair<int, int>> to_travel;
        
        while (seed.first < _X) {
            while(checkValid(seed.first, seed.second) and grid[seed.first][seed.second] == _water){
                while (checkValid(seed.first, seed.second) and grid[seed.first][seed.second] == _water) {
                    seed.second++;
                }
                if (checkValid(seed.first, seed.second)) {
                    // find a land
                    break;
                }
                // keep searching
                seed.first++;
                seed.second = 0;
            }
            if (seed.first >= _X) {
                break;
            }
            addToQueue(grid, to_travel, seed.first, seed.second);
            
            while (!to_travel.empty()) {// bfs
                // travel
                pair<int, int> now = to_travel.front();
                to_travel.pop();
                visit(grid, now);
                
                // up, right, down, left
                if (checkValid(now.first, now.second+1) and grid[now.first][now.second+1] == _land) {
                    addToQueue(grid, to_travel, now.first, now.second+1);
                }
                if (checkValid(now.first, now.second-1) and grid[now.first][now.second-1] == _land) {
                    addToQueue(grid, to_travel, now.first, now.second-1);
                }
                if (checkValid(now.first+1, now.second) and grid[now.first+1][now.second] == _land) {
                    addToQueue(grid, to_travel, now.first+1, now.second);
                }
                if (checkValid(now.first-1, now.second) and grid[now.first-1][now.second] == _land) {
                    addToQueue(grid, to_travel, now.first-1, now.second);
                }
            }
            answ ++;
        }
        
        return answ;
    }
};


int main(){
    Solution solve;
    vector<vector<char>> inputs(4);
    
    /*
     11110
     11010
     11000
     00000
     
     11000
     11000
     00100
     00011
     */
    inputs[0] = {'1', '1', '0', '0', '1'};
    inputs[1] = {'1', '1', '0', '1', '0'};
    inputs[2] = {'0', '0', '1', '1', '0'};
    inputs[3] = {'1', '0', '1', '1', '1'};
    
    
    inputs = vector<vector<char>>(3);
    inputs[0] = {'0', '1', '0'};
    inputs[1] = {'1', '0', '1'};
    inputs[2] = {'0', '1', '0'};
    cout << solve.numIslands(inputs) << "\n";
    return 0;
}