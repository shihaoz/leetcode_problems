//
//  leetcode_longest_palindrome_substring.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/6/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_longest_palindrome_substring.hpp"
#include "common.h"

class Solution {
    /**
     method 1: recursion
     */
    void _recursion(int left, int right, string subString);
    string _longest;
    string _word;
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        _longest = s[0];   _word = s;

        return _longest;
    }
};

void Solution::_recursion(int left, int right, string subString){
    if (left >= right) {
        int size = subString.size();
        if (left == right) {
            subString += _word[left];
        }
        string tmp = subString.substr(0, size); reverse(tmp.begin(), tmp.end());
        subString += tmp;
        if (subString.length() > _longest.length()) {
            _longest = subString;
        }
    }
    else{
        if (_word[left] == _word[right]) {
            this->_recursion(left+1, right-1, subString + _word[left]);
        }
            this->_recursion(left+1, right, "");
            this->_recursion(left, right-1, "");
    }
}

const vector<string> _testcases = {
    "",
    "a",
    "abcddcefg",
    "aaabaaaa",
};

int main(){
    Solution solve;
    for (string str : _testcases) {
        cout << solve.longestPalindrome(str) << '\n';
    }
    return 0;
}