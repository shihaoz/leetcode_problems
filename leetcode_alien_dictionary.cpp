//
//  leetcode_alien_dictionary.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/2/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_alien_dictionary.hpp"


class Solution {
    unordered_map<char, unordered_set<char>> _adjList;
    unordered_map<char, int> _inDegree;
    bool check(vector<string> words, int pos, int start, int end);
public:
    string alienOrder(vector<string>& words) {
        if (words.empty()) {
            return "";
        }
        this->_inDegree.clear();    this->_adjList.clear();
        for (string str : words) {// initialize in-degree
            for (char c : str) {
                this->_inDegree[c] = 0;
            }
        }
        // build adjacency list
        for (int i = 0, idx = 0; i < words.size()-1; i++) {
            string word1 = words[i], word2 = words[i+1];
            for (idx = 0; idx < min(word1.length(), word2.length()); idx++) {
                if (word1[idx] != word2[idx]) {
                    this->_adjList[word1[idx]].insert(word2[idx]);
                    break;
                }
            }
            if (idx >= min(word1.length(), word2.length()) and
                word1.length() > word2.length()) {
                return "";
            }
        }
        
        // build In-Degree list
        for (auto it = this->_adjList.begin(); it != this->_adjList.end(); it++) {
            for (auto it_in = it->second.begin(); it_in != it->second.end(); it_in++) {
                this->_inDegree[*it_in]++;
            }
        }
        // build topological sort
        string answ;
        queue<char> nexts;
        for (auto it = this->_inDegree.begin(); it != this->_inDegree.end(); it++) {
            if (it->second == 0) {
                nexts.push(it->first);
            }
        }
        while (!nexts.empty()) {
            char now = nexts.front();   nexts.pop();
            answ += now;
            for (auto it = this->_adjList[now].begin(); it != this->_adjList[now].end(); it++) {
                this->_inDegree[*it]--;
                if (this->_inDegree[*it] == 0) {
                    nexts.push(*it);
                }
            }
        }
        return (answ.length() == this->_inDegree.size()) ? answ : "";
    }
};

const vector<vector<string>> _testcases = {
    {
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"
    },
    {
        "abc",
        "adc",
        "a",
    },
    {
        
    },
    {
        "z",
        "z",
    },
    {
        "t",
        "wrf",
        "wrt",
        "ee",
        "eft",
    },
    {
        "wrf",
        "wrt",
        "ee",
        "eft",
    },
    {
        "wrtkj","wrt"
    },
};
int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.alienOrder(test) << '\n';
    }
    return 0;
}