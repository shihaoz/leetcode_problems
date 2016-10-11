//
//  fb_regex.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_regex.hpp"

class Solution {
    string _str, _reg;
    bool _recursion(int idxStr, int idxReg);

public:
    bool isMatch(string s, string p) {
        if (s.empty() or p.empty()) {
            if (s.empty()) {
                bool all_stars = true;
                for (int i = 1; i < p.size(); i += 2) {
                    if (p[i] != '*') {
                        all_stars = false;  break;
                    }
                }
                return all_stars and p.size()%2 == 0;
            }
            return false;
        }
        vector<vector<bool>> _states(s.length()+1, vector<bool>(p.length()+1, false));
        _states[0][0] = true;
        for (int i = 0; i < _states.size(); i++) {
            for (int j = 0; j < _states[i].size(); j++) {
                if (_states[i][j]) {
                    /// end condition
                    if (i == s.length() and j == p.length()) {  // string matched
                        _states[i][j] = true;
                        continue;
                    }
                    else if(j == p.length()){   // string not fully matched
                        continue;
                    }
                    else if(i == s.length()){   // more regex
                        if (j + 1 < p.length() and p[j+1] == '*') {// if star
                            _states[i][j+2] = true;
                        }
                        continue;
                    }
                    /// not end
                    if (j + 1 < p.length() and p[j+1] == '*') { // star match
                        _states[i][j+2] = true; // match 0
                        if (p[j] == s[i] or p[j] == '.') {
                            _states[i+1][j] = true; // match 1
                        }
                    }
                    else{
                        if (p[j] == s[i] or p[j] == '.') {
                            _states[i+1][j+1] = true;   // match 1
                        }
                    }
                }
            }
        }
        return _states.back().back();
    }
};

bool Solution::_recursion(int idxStr, int idxReg){
    /// end condition
    if (idxStr == _str.length() and idxReg == _reg.length()) {  // string matched
        return true;
    }
    else if(idxReg == _reg.length()){   // string not fully matched
        return false;
    }
    else if(idxStr == _str.length()){   // more regex
        if (idxReg + 1 < this->_reg.length() and this->_reg[idxReg+1] == '*') {// if star
            return this->_recursion(idxStr, idxReg+2);
        }
        else{
            return false;
        }
    }
    /// not end

    bool answ = false;
    if (idxReg + 1 < this->_reg.length() and this->_reg[idxReg+1] == '*') { // star match
        answ = answ | this->_recursion(idxStr, idxReg+2);   // match 0
        if (_reg[idxReg] == _str[idxStr] or _reg[idxReg] == '.') {
            answ = answ | this->_recursion(idxStr+1, idxReg);   // match 1
        }
    }
    else{
        if (_reg[idxReg] == _str[idxStr] or _reg[idxReg] == '.') {
            answ = answ | this->_recursion(idxStr+1, idxReg+1);
        }
    }
    return answ;
}

struct TEST{
    string target, regex;
};
const vector<TEST> _testcases = {
    {
        "aa", "a*b*",
    },
    {
        "aab", "c*a*b*",
    },
    {
        "aa", "a*b",
    },
    {
        "aa", "a",
    },
    {
        "aa", "b*.*",
    },
    {
        "",
        "a*.*",
    },
    {
        "",
        ".",
    },
};

int main(){
    Solution solve; cout << boolalpha;
    for (auto test : _testcases) {
        cout << solve.isMatch(test.target, test.regex) << '\n';
    }
    return 0;
}