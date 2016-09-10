//
//  leetcode_regex_matching.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/31/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_regex_matching.hpp"
struct _TEST{
    string src;
    string regex;
};
const vector<_TEST> _testcases = {
    {"aa", "a"},    // false
    {"aa", "aa"},   // true
    {"aaa", "aa"},  // false
    {"aa", "a*"},   // true
    {"aa", ".*"},   // true
    {"ab", ".*"},   // true
    {"aab", "c*a*b"},    // true
    {"aabbbaa", "a*.*bba*a"}, // true
    {"ab",".*c"},    // false
    {"a", "ab*"},    // true
};

class Solution {
    const char _any = '.';
    const char _0more = '*';
public:
    bool isMatch(string target, string match) {

        
        return false;
    }
};

int main(){
    Solution solve;
    cout << boolalpha;
    for (auto test : _testcases) {
        cout << solve.isMatch(test.src, test.regex) << "\n";
    }
    return 0;
}