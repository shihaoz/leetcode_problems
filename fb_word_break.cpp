//
//  fb_word_break.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_word_break.hpp"

class Solution {
    bool _helper_recursion(string& a, int start, int idx, unordered_set<string>& wordDict);
public:
    bool wordBreak(string s, unordered_set<string>& wordDict);
};
bool Solution::wordBreak(string s, unordered_set<string> &wordDict){
    if (s.empty()) {
        return false;
    }
    vector<bool> _states(s.length(), false);
    vector<int> _true_index;
    size_t max_length = 0, min_length = s.length();
    for (auto it = wordDict.begin(); it != wordDict.end(); it++) {
        max_length = max(max_length, it->size());
        min_length = min(min_length, it->size());
    }
    for (int i = 0; i < s.length(); i++) {
        if (wordDict.find(s.substr(0, i+1)) != wordDict.end()) {
            _states[i] = true;
            _true_index.push_back(i);
        }
        else{
            for (int idx : _true_index) {
                int size = i-(idx+1)+1;
                if (size <= max_length  and
                    size >= min_length  and
                    wordDict.find(s.substr(idx+1, i-(idx+1)+1)) != wordDict.end()) {
                    _states[i] = true;
                    _true_index.push_back(i);
                    break;
                }
            }
        }
    }
    return _states[s.length()-1];
}
bool Solution::_helper_recursion(string &a, int start, int idx, unordered_set<string>& wordDict){
    if (start == a.length()) {
        return true;
    }
    if (idx >= a.length()) {
        return false;
    }
    if (wordDict.find(a.substr(start, idx-start+1)) != wordDict.end()) {
        // word exists
        if (this->_helper_recursion(a, idx+1, idx+1, wordDict)) {
            return true;
        }
    }
    if (this->_helper_recursion(a, start, idx+1, wordDict)) {
        return true;
    }
    return false;
}

struct TEST{
    string str;
    unordered_set<string> words;
};

const vector<TEST> _testcases = {
    {
        "leetcode",
        {"leet", "code"},
    },
    {
        "abcdefghijk",
        {"abcd", "ef", "fghijk"},
    }
};

int main(){
    Solution solve; cout << boolalpha;
    for (TEST test : _testcases) {
        cout << solve.wordBreak(test.str, test.words) << "\n";
    }
    return 0;
}