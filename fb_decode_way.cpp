//
//  fb_decode_way.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/3/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_decode_way.hpp"

class Solution {
    void _recursion(int pos, string s, int &count);
public:
    int numDecodings(string s) {
        int count = 0;
        if (s.empty() or s[0] == '0') {
            return count;
        }
//        this->_recursion(0, s, count);
        vector<int> _states(s.length()+1, 0); _states[0] = 1;
        for (int pos = 0; pos < _states.size()-1; pos++) {
            if (s[pos] == '0') {
                _states[pos] = 0;
            }
            else{
                _states[pos+1] += _states[pos];
                if (pos+1 < s.length() and atoi(s.substr(pos,2).c_str()) <= 26) {
                    _states[pos+2] += _states[pos];
                }
            }
        }
        return _states.back();
    }
};

void Solution::_recursion(int pos, string s, int &count){
    if (pos == s.length()) {
        count ++;
    }
    else{
        if (s[pos] == '0') {// invalid
            return;
        }
        this->_recursion(pos+1, s, count);
        if (pos+1 < s.length() and atoi(s.substr(pos, 2).c_str()) <= 26) {
            this->_recursion(pos+2, s, count);
        }
    }
}

const vector<string> _testcases = {
    "120",
    "1010",
    "123",
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.numDecodings(test) << "\n";
    }
    return 0;
}
