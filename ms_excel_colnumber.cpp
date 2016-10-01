//
//  ms_excel_colnumber.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_excel_colnumber.hpp"

class Solution {
public:
    int titleToNumber(string s) {
        int answ = 0, factor = 1;
        for (int i = s.length()-1; i >= 0; i--, factor *= 26) {
            answ += (s[i]-'A'+1)*factor;
        }
        return answ;
    }
};

const vector<string> _testcases = {
    "AB",
    "ZZ",
    "AAA",
    "ABAB",
    "Z",
};

int main(){
    Solution solve;
    for (string str : _testcases) {
        cout << solve.titleToNumber(str) << "\n";
    }
    return 0;
}