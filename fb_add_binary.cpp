//
//  fb_add_binary.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/3/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_add_binary.hpp"


class Solution {
    int _toNum(char a){return a - '0';}
public:
    string addBinary(string a, string b) {
        int idx1 = a.length()-1, idx2 = b.length()-1, carryBit = 0;
        string answ;
        while (idx1 >= 0 and idx2 >= 0) {
            int now = _toNum(a[idx1--]) + _toNum(b[idx2--]) + carryBit;
            answ = to_string(now%2) + answ;
            carryBit = now/2;
        }
        while (idx1 >= 0) {
            int now = _toNum(a[idx1--]) + carryBit;
            answ = to_string(now%2) + answ;
            carryBit = now/2;
        }
        while (idx2 >= 0) {
            int now = _toNum(b[idx2--]) + carryBit;
            answ = to_string(now%2) + answ;
            carryBit = now/2;
        }
        if (carryBit) {
            answ = '1' + answ;
        }
        return answ;
    }
};

const vector<pair<string, string>> _testcases = {
    {
        "11", "1",
    },
    {
        "111", "1111",
    },
    {
        "", "10",
    },
    {
        "11", "1010",
    }
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.addBinary(test.first, test.second) << "\n";
    }
    return 0;
}