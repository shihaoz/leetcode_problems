//
//  leetcode_regex.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_regex.hpp"

struct REGEX {
    char character;
    bool star;
};
class Solution {
    string _input;
    vector<REGEX> _regex;
    int _remain_single_characters;
    
    void _init(string s){
        this->_input = s;
        this->_regex.clear();
        this->_remain_single_characters = 0;
    }
    
    bool _helper_recursion(int i, int j);
    bool _helper_dp();
public:
    bool isMatch(string s, string p) {
        this->_init(s);
        
        for (char c : p) {
            if (c == '*') {
                _regex.back().star = true;
                this->_remain_single_characters--;
            }
            else{
                _regex.push_back({c, false});
                this->_remain_single_characters++;
            }
        }
//        return _helper_recursion(0, 0);
        return _helper_dp();
    }
};

bool Solution::_helper_recursion(int i, int j){
    if (i == _input.size()) {
        // end condition
        while (j < _regex.size()) {
            if (!this->_regex[j].star) {
                return false;
            }
            j++;
        }
        return true;
    }
    if (j == this->_regex.size()) {
        return false;
    }
    
    if (!this->_regex[j].star) {
        if (this->_regex[j].character == this->_input[i] or
            this->_regex[j].character == '.') {
            // match
            return this->_helper_recursion(i+1, j+1);
        }
        else{
            return false;
        }
    }
    else if(this->_regex[j].character != '.'){
        // character*
        int idx = i;
        // match zero
        if (this->_helper_recursion(idx, j+1)) {
            return true;
        }
        // match >= 1
        while (idx < this->_input.size() and this->_input[idx] == this->_regex[j].character) {
            if (this->_helper_recursion(idx+1, j+1)) {
                return true;
            }
            idx++;
        }
    }
    else{
        // .*
        int idx = i;
        if (this->_helper_recursion(idx, j+1)) {
            return true;
        }
        while (idx < this->_input.size()) {
            if (this->_helper_recursion(idx+1, j+1)) {
                return true;
            }
            idx++;
        }
    }
    return false;
}


bool Solution::_helper_dp(){
    vector<vector<bool>> _states(this->_input.size()+1, vector<bool>(this->_regex.size()+1, false));

    // initialize last row
    int last_row = _states.size()-1;
    for (int i = 0; i < _states[last_row].size(); i++) {
        if (this->_remain_single_characters == 0) {
            _states[last_row][i] = true;
        }
        else if(!this->_regex[i].star){
            this->_remain_single_characters --;
        }
    }

    // recursion from i = this->input.size()->0
    //                  j = this->_regex.size()-1 -> 0
    for (int i = this->_input.size()-1; i >= 0; i--) {
        for (int j = this->_regex.size()-1; j >= 0; j--) {
            if (!this->_regex[j].star) {
                /** single character case
                 look at [i+1][j+1]
                 */
                if (this->_regex[j].character == this->_input[i]
                    or
                    this->_regex[j].character == '.') {
                    _states[i][j] = _states[i+1][j+1];
                }
                else{
                    _states[i][j] = false;
                }
            }
            else {
                /**
                 “sth*”
                 match == 0 or >= 1
                 */
                _states[i][j] = (_states[i][j+1])
                                    or
                                ((this->_input[i] == this->_regex[j].character or this->_regex[j].character == '.')
                                    and
                                 _states[i+1][j]);
            }
        }
    }
    return _states[0][0];
}


struct TEST {
    string input, regex;
};
const vector<TEST> _testcases = {
    {"aa", "a"},        // false
    {"abc", "ac"},       // false
    {"aa", "aa"},       // true
    {"ab", ".*"},       // true
    {"aab", "c*a*b"},   // true
    {"abcdba", ".*a.*cdba"},    // true
    {"aaa", "a.a"},     // true
    {"aaabbccdbd", "a*b*c*db.*"},    // true
    {"abcd", "d*d"},                // false
};
int main(){
    Solution solve;
    cout << boolalpha;
    for(auto test: _testcases){
        cout << solve.isMatch(test.input, test.regex) << "\n";
    }
    return 0;
}