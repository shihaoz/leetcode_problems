//
//  leetcode_decodeway.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_decodeway.hpp"
class Solution {
    int _helper(string s, int idx);
    int _helper_dp(string s);
public:
    int numDecodings(string s);
};
int Solution::_helper(string s, int idx){
    if (idx >= s.size()) {
        return 1;
    }
    if (s[idx] == '0' or isalpha(s[idx])) {
        // invalid
        return 0;
    }
    
    return this->_helper(s, idx+1) +
        ((s.size()-idx >= 2 and atoi(s.substr(idx, 2).c_str()) <= 26) ?
        this->_helper(s, idx+2) : 0);
}

int Solution::numDecodings(string s){
    if (s.empty()) {
        return 0;
    }
//    return this->_helper(s, 0);
    return this->_helper_dp(s);
}

int Solution::_helper_dp(string s) {
    vector<int> _states(s.size()+1, 0);
    
    if (s[0] == '0' or isalpha(s[0])) {
        return 0;
    }
    // set initial
    _states.back() = 1;
    int idx = s.size()-1;
    while (idx >= 0) {
        if (s[idx] == '0' or isalpha(s[idx])) {
            _states[idx] = 0;
        }
        else{
            _states[idx] += _states[idx+1] +
            ((s.size()-idx >= 2 and atoi(s.substr(idx, 2).c_str()) <= 26) ? _states[idx+2] : 0);
        }
        idx--;
    }
    
    return _states[0];
}

const vector<string> _testcases = {
    "12",       // #2
    "49",       // #1
    "7",        // #1
    "2613",     // #4
    "100",      // 0
    "10",       // 1
    "ab",     // 0
    "123ab",      // 0
};
int main(){
    Solution solve;
    
    for (string s : _testcases) {
        cout << s << "-> " << solve.numDecodings(s) << "\n";
    }
    return 0;
}