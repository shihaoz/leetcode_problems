//
//  leetcode_no_repeat_substring.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/20/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_no_repeat_substring.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        int max_length = 0;
        int head = 0, tail = 1; unordered_set<char> _lookup;
        _lookup.insert(s[0]);
        while (tail < s.size()) {
            while (tail < s.size() and _lookup.find(s[tail]) == _lookup.end()) {
                _lookup.insert(s[tail++]);
            }
            max_length = max(max_length, tail-head);
            if (tail == s.size()) {
                break;
            }
            while (s[head] != s[tail]) {
                _lookup.erase(s[head++]);
            }
            _lookup.erase(s[head++]);
        }
        return max_length;
    }
};
const vector<string> _testcases = {
    "abcabcbb",
    "bbbbb",
    "pwwkew",
    "a",
};
int main(){
    Solution solve;
    
    for (string str : _testcases) {
        cout << solve.lengthOfLongestSubstring(str) << '\n';
    }
    return 0;
}