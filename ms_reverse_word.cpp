//
//  ms_reverse_word.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/26/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_reverse_word.hpp"

class Solution {
public:
    void reverseWords(string &s) {
        // reverse entire string
        reverse(s.begin(), s.end());
        size_t start = s.find_first_not_of(' '), end = s.find(' ', start);
        while (end != s.npos) {
            reverse(s.begin()+start, s.begin()+end);
            start = s.find_first_not_of(' ', end+1);
            end = s.find(' ', start);
        }
        if (start != string::npos) {
            reverse(s.begin()+start, s.end());
        }
        
    
        /// trim all whitespaces to exactly 1 whitespace
        start = s.find_first_of(' ');
        end = s.find_first_not_of(' ', start);
        while (end != s.npos) {
            s.erase(s.begin()+start, s.begin()+end-1);  // leave only one whitespace
            start = s.find_first_of(' ', start+1);
            end = s.find_first_not_of(' ', start);
        }
        /// leading and trailing
        start = s.find_first_not_of(' ');
        if (start != s.npos) {
            s.erase(s.begin(), s.begin()+start);
        }
        else{
            s.clear();
        }
        start = s.find_last_not_of(' ');
        if (start != s.npos) {
            s.erase(s.begin()+start+1, s.end());
        }

    }
};

const vector<string> _testcases = {
    "the sky is blue",
    "  the  sky is   blue  ",
    " ",
    " abbbbbb ",
    "   abc def ",
    "a",
    " a",
    "ab",
};

int main(){
    Solution solve;
    for (string str : _testcases) {
        solve.reverseWords(str);
        cout << str << "*\n";
    }
    return 0;
}