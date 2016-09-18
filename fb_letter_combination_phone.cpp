//
//  fb_letter_combination_phone.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_letter_combination_phone.hpp"

class Solution {
    unordered_map<int, string> _lookup = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };
public:
    vector<string> letterCombinations(string digits);
};


vector<string> Solution::letterCombinations(string digits) {
    if (digits.empty()) {
        return {};
    }
    
    // setup
    vector<string> _answ(1, "");
    for (int i = 0; i < digits.size(); i++) {
        // if not found, return empty {}
        if (this->_lookup.find(digits[i]-'0') == this->_lookup.end()) {
            return {};
        }
        // change one + append
        string char_list = this->_lookup[digits[i]-'0'];
        int size = _answ.size();
        for (int j = 0; j < size; j++) {
            for (int idx = 1; idx < char_list.length(); idx ++) {
                _answ.push_back(_answ[j] + char_list[idx]);
            }
            _answ[j] += char_list[0];
        }
    }
    return _answ;
}


const vector<string> _testcases = {
    "23",
    "2314",
    "2534",
    "",
    "908",
    "9",
};

int main(){
    Solution solve;
    for (string str : _testcases) {
        dzCommon::printArray(solve.letterCombinations(str), true);
        cout << dzCommon::seperator;
    }
    return 0;
}