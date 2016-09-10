//
//  leetcode_valid_parenthese.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/3/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_valid_parenthese.hpp"

bool isLeftParam(char c){
    return c == '(';
}
bool isRightParam(char c){
    return c == ')';
}
bool isLeftCurly(char c){
    return c == '{';
}
bool isRightCurly(char c){
    return c == '}';
}
bool isLeftSquare(char c){
    return c == '[';
}
bool isRightSquare(char c){
    return c == ']';
}
bool isLeft(char c){
    return isLeftParam(c) or isLeftCurly(c) or isLeftSquare(c);
}
bool isRight(char c){
    return isRightParam(c) or isRightCurly(c) or isRightSquare(c);
}
class Solution {
    
public:
    bool isValid(string s) {
        stack<char> _parentheses;
        if (s.size() % 2 == 1) {
            return false;
        }
        int idx = 0;
        while (idx < s.size()) {
            if (_parentheses.empty() and isRight(s[idx])) {
                return false;
            }
            if (isLeft(s[idx])) {
                _parentheses.push(s[idx]);
            }
            else{// this is a right
                if ((isRightParam(s[idx]) and isLeftParam(_parentheses.top()))
                    or
                    (isRightSquare(s[idx]) and isLeftSquare(_parentheses.top()))
                    or
                    (isRightCurly(s[idx]) and isLeftCurly(_parentheses.top()))
                    ) {
                    _parentheses.pop();
                }
                else{
                    return false;
                }
            }
            idx++;
        }
        return _parentheses.empty();
    }
};

const vector<string> _testcases = {
    "()[]{}",   // true
    "(]",       // false
    "(([{[]}]))",   // true
    "([)]",     // false
    "(",        // false
    ")",        // false
    "()]",      // false
};
int main(){
    Solution solve;
    cout << boolalpha;
    
    for (auto s : _testcases) {
        cout << solve.isValid(s) << "\n";
    }
    
    return 0;
}