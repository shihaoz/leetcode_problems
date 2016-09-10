//
//  leetcode_letter_combination.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/6/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_letter_combination.hpp"

class Solution {

    
    void _helper_recursion(string digits, int i, string last,
                           unordered_map<int, string>& _phone_hash,
                           vector<string>& _answ);
public:
    vector<string> letterCombinations(string digits) {
        vector<string> _answ;
        if (!digits.empty()) {
            unordered_map<int, string> _phone_hash = {
                {0, {}},
                {1, {}},
                {2, {"abc"}},
                {3, {"def"}},
                {4, {"ghi"}},
                {5, {"jkl"}},
                {6, {"mno"}},
                {7, {"pqrs"}},
                {8, {"tuv"}},
                {9, {"wxyz"}}
            };
            _helper_recursion(digits, 0, "", _phone_hash, _answ);
        }
        return _answ;
    }
};
void Solution::_helper_recursion(string digits, int i, string last,
                       unordered_map<int, string>& _phone_hash,
                       vector<string>& _answ){
    if (i == digits.size()) {
        _answ.push_back(last);
    }
    else{
        string opts = _phone_hash[digits[i] - '0'];
        for(char c : opts){
            _helper_recursion(digits, i+1, last+c, _phone_hash, _answ);
        }
    }
}
const vector<string> _testcases = {
    "23",       // []x9
    "1",        // []
    "287",       // []x9
    "09",       // []
};
void printArray(vector<string> in){
    for (string s : in) {
        cout << s << " ";
    }cout << "\n";
}
int main(){
    Solution solve;
    for (string str : _testcases) {
        printArray(solve.letterCombinations(str));
    }
    return 0;
}