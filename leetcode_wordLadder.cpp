//
//  leetcode_wordLadder.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_wordLadder.hpp"

class Solution {
    string _beginWord, _endWord;
    vector<vector<string>> _result;
    int min_length;
    
    bool _reachable(string word1, string word2);
    void _helper_recursion(string word, unordered_map<string, bool>& visited, unordered_set<string>& wordList, vector<string> result);
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        this->_result.clear();
        min_length = wordList.size()+1;
        this->_beginWord = beginWord;   this->_endWord = endWord;
        unordered_map<string, bool> visited;
        for (auto it = wordList.begin(); it != wordList.end(); it++) {
            visited[*it] = false;
        }
        wordList.insert(endWord);
        this->_helper_recursion(beginWord, visited, wordList, {beginWord});
        
        return this->_result;
    }
};

bool Solution::_reachable(string word1, string word2){
    int diff = 0;
    for (int i = 0; i < word1.size() and diff < 2; i++) {
        if (word1[i] != word2[i]) {
            diff++;
        }
    }
    return diff < 2;
}

void Solution::_helper_recursion(string word, unordered_map<string, bool> &visited, unordered_set<string>& wordList, vector<string> result){
    if (word == this->_endWord) {
        if (result.size() < min_length) {
            min_length = result.size();
            this->_result.clear();
        }
        this->_result.push_back(result);
    }
    else if(result.size() < min_length){
        for (auto it = wordList.begin(); it != wordList.end(); it++) {
            if (!visited[*it] and
                this->_reachable(*it, word)) {
                visited[*it] = true;
                result.push_back(*it);
                this->_helper_recursion(*it, visited, wordList, result);
                result.erase(result.end()-1);
                visited[*it] = false;
            }
        }
    }
}

struct TEST{
    unordered_set<string> words;
    string startWord, endWord;
};
const vector<TEST> _testcases = {
    {
        {"hot","dot","dog","lot","log"},
        "hit", "cog",
    },
    {
        {"ai"},
        "hi", "ci"
    },
    {
        {"abb", "aaa"},
        "abc", "acd",
    }
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        dzCommon::printArrayArray(
                    solve.findLadders(test.startWord, test.endWord, test.words), true
                );
    }
    return 0;
}