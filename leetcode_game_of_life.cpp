//
//  leetcode_game_of_life.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_game_of_life.hpp"

class Solution {
    void checkHere(int i, int j, vector<vector<int>>& board);
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) {
            return;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                this->checkHere(i, j, board);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                // 1. live, and 2 or 3
                // 2. dead and exactly 3
                if ((board[i][j]/10 == 1 and (board[i][j]%10 == 2 or board[i][j]%10 == 3))
                    or
                    (board[i][j]/10 == 0 and board[i][j]%10 == 3)
                    ) {
                    board[i][j] = 1;
                }
                else{
                    board[i][j] = 0;
                }
            }
        }
        return;
    }
};

void Solution::checkHere(int i, int j, vector<vector<int> > &board){
    int new_num = board[i][j]*10;
    // lower left, mid, right
    if (i-1 >= 0) {
        if (j-1 >= 0) {
            new_num += (board[i-1][j-1]/10);
        }
        new_num += (board[i-1][j]/10);
        if (j+1 < board[i-1].size()) {
            new_num += (board[i-1][j+1]/10);
        }
    }
    // left, (skip self), right
    if (j-1 >= 0) {
        new_num += (board[i][j-1]/10);
    }
    
    if (j+1 < board[i].size()) {
        new_num += board[i][j+1];
    }
    
    // upper left, mid, right
    if (i+1 < board.size()) {
        if (j-1 >= 0) {
            new_num += board[i+1][j-1];
        }
        new_num += board[i+1][j];
        if (j+1 < board[i+1].size()) {
            new_num += board[i+1][j+1];
        }
    }
    board[i][j] = new_num;
}


const vector<vector<vector<int>>> _testcases = {
//    {
//        {0,1,0},
//        {1,1,1},
//        {1,0,1},
//    },
//    {
//        {1},
//    },
//    {
//        {1,1,0,0},
//        {0,1,0,0},
//    },
    {
        {1,1,0,0},
        {0,1,0,0},
        {1,0,1,1},
    },
};

int main(){
    Solution solve;
    for (auto matrix : _testcases) {
        solve.gameOfLife(matrix);
        dzCommon::printArrayArray(matrix, true);
    }
    return 0;
}