//
//  fb_decodes.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/17/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_decodes.hpp"


class Solution {
public:
    int numDecodings(string s);
};

int Solution::numDecodings(string s){
    if (s.empty()) {
        return 0;
    }
    // setup
    vector<int> _states(s.size()+1, 0);
    _states[0] = 1;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] != '0') {
            _states[i+1] += _states[i];
            if (i < s.size()-1 and atoi(s.substr(i, 2).c_str()) <= 26) {
                _states[i+2] += _states[i];
            }
        }
    }
    return _states[s.size()];
}

const vector<string> _testcases = {
    "1126",
    "126",
    "136",
    "36",
    "00",
    "1001",
    "0",
    "1026",
};

int main(){
    Solution solve;
    for (string str : _testcases) {
        cout << solve.numDecodings(str) << "\n";
    }
    return 0;
}