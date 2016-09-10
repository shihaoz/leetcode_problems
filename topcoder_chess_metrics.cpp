//
//  topcoder_chess_metrics.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/30/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "topcoder_chess_metrics.hpp"


class Solution {
    int _size;
    bool checkValid(int x, int y){
        return x >= 0 and y >= 0 and x < this->_size and y < this->_size;
    }
    const vector<pair<int, int>> _moves = {
        // <height, width>
        /// all L moves
        make_pair(1, -2),
        make_pair(1, 2),
        make_pair(-1, -2),
        make_pair(-1, 2),
        
        make_pair(2, 1),
        make_pair(2, -1),
        make_pair(-2, 1),
        make_pair(-2, -1),
        
        /// all diagnal moves
        make_pair(1, 1),
        make_pair(1, -1),
        make_pair(-1, 1),
        make_pair(-1, -1),
        
        /// all neighbor moves
        make_pair(1, 0),
        make_pair(-1, 0),
        make_pair(0, 1),
        make_pair(0, -1),
    };

    vector<vector<long>> getBoard(){
        return vector<vector<long>>(this->_size, vector<long>(this->_size, 0));
    }
public:
    
    long howMany(int size, vector<int> start, vector<int> end, int numMoves){
        this->_size = size;
        pair<int, int> src(start[0], start[1]), dest(end[0], end[1]);
        
        auto board_now = this->getBoard(), board_next = this->getBoard();
        board_now[src.first][src.second] = true;
        
        for (int round = 0; round < numMoves; round++) {
            for (int i = 0; i < board_now.size(); i++) {
                for (int j = 0; j < board_now[i].size(); j++) {
                    if (board_now[i][j] > 0) {
                        // set moves
                        for (auto& p : this->_moves) {
                            int x = i + p.first, y = j + p.second;
                            if (checkValid(x, y)) {
                                board_next[x][y] += board_now[i][j];
                            }
                        }
                    }
                }
            }
            board_now = board_next;
            board_next = getBoard();
        }
        // on numMoves-th
        return board_now[dest.first][dest.second];
    }
};

int main(){
    Solution solve;
    cout << solve.howMany(3, {0, 0}, {1, 0}, 1) << "\n";
    cout << solve.howMany(3, {0, 0}, {2, 2}, 1) << "\n";
    cout << solve.howMany(3, {0, 0}, {0, 0}, 2) << "\n";
    cout << solve.howMany(100, {0, 0}, {0, 99}, 50) << "\n";
    return 0;
}