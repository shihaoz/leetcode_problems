//
//  fb_string_multiply.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_string_multiply.hpp"


class Solution {
    string _addString(string a, string b);
    string _multiplyString(string a, int mult);
public:
    string multiply(string num1, string num2) {
        string answ = "0";
        int level = 0;
        for (int i = num2.length()-1; i >= 0; i--, level++) {
            int mult = num2[i] - '0';
            if (mult > 0) {
                string result = this->_multiplyString(num1, mult);
                result += string(level, '0');
                answ = this->_addString(answ, result);
            }
        }
        int first_non_zero = 0;
        while (answ[first_non_zero] == '0') {
            first_non_zero++;
        }
        return (first_non_zero < answ.length()) ?
        answ.substr(first_non_zero) : "0";
    }
};

string Solution::_addString(string a, string b){
    string answ;
    int carryBit = 0, idx1 = a.length()-1, idx2 = b.length()-1;
    while (idx1 >= 0 and idx2 >= 0) {
        int now = a[idx1--] - '0' + b[idx2--] - '0' + carryBit;
        carryBit = now/10;
        answ = to_string(now%10) + answ;
    }
    while (idx1 >= 0) {
        int now = a[idx1--] - '0' + carryBit;
        carryBit = now/10;
        answ = to_string(now%10) + answ;
    }
    while (idx2 >= 0) {
        int now = b[idx2--] - '0' + carryBit;
        carryBit = now/10;
        answ = to_string(now%10) + answ;
    }
    if (carryBit > 0) {
        answ = '1' + answ;
    }
    return answ;
}

string Solution::_multiplyString(string a, int mult){
    string answ;
    int carryNum = 0;
    for (int i = a.length()-1; i >= 0; i--) {
        int now = (a[i] - '0') * mult + carryNum;
        carryNum = now/10;
        answ = to_string(now%10) + answ;
    }
    if (carryNum) {
        answ = to_string(carryNum) + answ;
    }
    return answ;
}

const vector<pair<string, string>> _testcases = {
    {
        "123", "45",
    },
    {
        "123", "7",
    },
    {
        "7","7",
    },
    {
        "2016", "500",
    },
    {
        "0", "155",
    },
    {
        "0", "0",
    },
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        cout << solve.multiply(test.first, test.second) << '\n';
    }
    return 0;
}