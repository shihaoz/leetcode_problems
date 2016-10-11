//
//  fb_word_search.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_word_search.hpp"

class Solution {
    /**
     [x][y] matches word[idx], visited = coordinates already visited
     search [x+1][y] [x-1][y] [x][y+1] [x][y-1] for matching
     */
    bool _DFS(int x, int y, int idx, string word);
    const vector<pair<int, int>> _steps = {
        {1,0}, {-1,0}, {0,1}, {0,-1},
    };
    bool _ifValid(int x, int y);
    vector<vector<char>> _board;
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->_board = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) { // DFS
                    char tmp = this->_board[i][j];
                    this->_board[i][j] = '0';
                    if (this->_DFS(i, j, 0, word)) {
                        return true;
                    }
                    this->_board[i][j] = tmp;
                }
            }
        }
        return false;
    }
};
bool Solution::_ifValid(int x, int y){
    return x >= 0 and y >= 0 and x < _board.size() and y < _board[x].size();
}
bool Solution::_DFS(int x, int y, int idx, string word){
    if (idx == word.length()-1) {
        return true;
    }
    for (auto p : this->_steps) {
        int newX = x+p.first, newY = y+p.second;
        if (this->_ifValid(newX, newY) and
            this->_board[newX][newY] == word[idx+1]) {
            char temp = this->_board[newX][newY];
            this->_board[newX][newY] = '0';
            if (this->_DFS(newX, newY, idx+1, word)) {
                return true;
            }
            this->_board[newX][newY] = temp;
        }
    }
    return false;
}

struct TEST {
    vector<vector<char>> matrix;
    string word;
};
const vector<TEST> _testcases = {
//    {
//        {
//            {'A','B','C','E'},
//            {'S','F','C','S'},
//            {'A','D','E','E'}
//        },
//        "ABCCED",
//    },
//    {
//        {
//            {'A','B','C','E'},
//            {'S','F','C','S'},
//            {'A','D','E','E'}
//        },
//        "SEE",
//    },
//    {
//        {
//            {'A','B','C','E'},
//            {'S','F','C','S'},
//            {'A','D','E','E'}
//        },
//        "ABCB",
//    },
//    {
//        {},
//        "DAVID",
//    },
//    {
//        {{'D','A','V','I','D'}},
//        "DAVID",
//    },
    {
        {{'a', 'a'}},
        "aaa",
    },
};

int main(){
    Solution solve; cout << boolalpha;
    
    for (auto test : _testcases) {
        cout << solve.exist(test.matrix, test.word) << '\n';
    }
    return 0;
}