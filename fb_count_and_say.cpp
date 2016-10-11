//
//  fb_count_and_say.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_count_and_say.hpp"


class Solution {
    static unordered_map<int, string> _cheat;
    static int _maxSoFar;
public:
    string countAndSay(int n) {
        _cheat[1] = "1";
        
        string last = "1", next;
        if (_cheat.find(n) != _cheat.end()) {
            return _cheat[n];
        }
        last = _cheat[_maxSoFar];
        for (int i = _maxSoFar+1; i <= n; i++) {
            int count = 1;
            for (int j = 1; j < last.length(); j++) {
                if (last[j] == last[j-1]) {
                    count++;
                }
                else{
                    next += to_string(count) + last[j-1];
                    count = 1;  // clear count to 1
                }
            }
            next += to_string(count) + last.back();
            last = next;    next.clear();
            _cheat[i] = last;
            _maxSoFar = i;
        }
        
        return last;
    }
};
int Solution::_maxSoFar = 1;
unordered_map<int, string> Solution::_cheat;
const vector<int> _testcases = {
    3,
    4,
    5,
    6,
    10,
};

int main(){
    Solution solve;
    for (int test : _testcases) {
        cout << solve.countAndSay(test) << '\n';
    }
    return 0;
}