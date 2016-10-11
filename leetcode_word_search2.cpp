//
//  leetcode_word_search2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_word_search2.hpp"

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
                        this->_board[i][j] = tmp;
                        return true;
                    }
                    this->_board[i][j] = tmp;
                }
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> answ;
        unordered_set<string> unique_words;
        for (string str : words) {
            unique_words.insert(str);
        }
        vector<int> wordCount(26, 0);   // store word Count to eliminate words
        for (auto vec : board) {
            for (char c : vec) {
                wordCount[c-'a']++;
            }
        }
        for (auto it = unique_words.begin(); it != unique_words.end(); it++) {
            vector<int> count(26, 0);
            bool impossible = false;
            for (char c : *it) {
                count[c-'a']++;
            }
            for (int i = 0; i < wordCount.size() and !impossible; i++) {
                if (count[i] > wordCount[i]) {
                    impossible = true;
                }
            }
            if (impossible) {
                continue;
            }
            bool found = false;
            for (int j = 0; j < answ.size() and !found; j++) {
                if (answ[j].find(*it) != string::npos) {
                    answ.push_back(*it);
                    found = true;
                }
            }
            if (!found) {
                if(this->exist(board, *it)){
                    answ.push_back(*it);
                }
            }
        }
        return answ;
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
    vector<vector<char>> boards;
    vector<string> words;
};

const vector<TEST> _testcases = {
    {
        {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i', 'f', 'l', 'v'},
        },
        {"oath","pea","eat","rain"},
    },
    {
        {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i', 'f', 'l', 'v'},
        },
        {"oath","oath","eat","rain"},
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        auto ret = solve.findWords(test.boards, test.words);
        dzCommon::printArray(ret);
    }
    return 0;
}