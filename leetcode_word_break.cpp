//
//  ;
//  leetcode2016
//
//  Created by Shihao Zhang on 8/31/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_word_break.hpp"

struct _TEST {
    string word;
    unordered_set<string> dicts;
};

vector<_TEST> _testcases = {
    {"leetcode", {"leet", "code"}}, // regular 1
    {"davidisawesome", {"awesome", "david", "is"}}, // regular 2
    {"abcabc", {"abc"}},    // same word
    {"abcabcd", {"abcd", "abca"}}, // cannot complete
    {"abcd", {"a", "b", "c", "d"}},  // each character
    {"a", {"aa"}},  // cannot complete
    {"aaca", {"a","ac"}}, // can complete
};

class Solution {

public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.find(s) != wordDict.end()) {
            return true;
        }
        
        vector<bool> states(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            if (wordDict.find(s.substr(0, i+1)) != wordDict.end()) {
                states[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (states[j] and wordDict.find(s.substr(j+1, i-j)) != wordDict.end()) {
                    states[i] = true;
                    break;
                }
            }
        }
        return states.back();
    }
};


int main(){
    Solution solve;
    cout << boolalpha;
    
    for (auto test : _testcases) {
        cout << solve.wordBreak(test.word, test.dicts) << "\n";
    }
    
    return 0;
}