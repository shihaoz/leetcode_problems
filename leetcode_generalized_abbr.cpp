//
//  leetcode_generalized_abbr.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/24/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_generalized_abbr.hpp"

class Solution {
    
    void _helper(string word, int num_start, int num_end, vector<string>& answ);
public:
    vector<string> generateAbbreviations(string word) {
        if (word.empty()) {
            return {""};
        }
        vector<string> _answ;
        for (int i = 0; i < word.length(); i++) {
            _answ.push_back(word.substr(0,i) + '1' + word.substr(i+1));
        }
        for (int i = 0; i < word.length(); i++) {
            this->_helper(_answ[i], i, i, _answ);
        }
        _answ.push_back(word);
        return _answ;
    }
};
void Solution::_helper(string word, int num_start, int num_end, vector<string> &answ){
    if (num_end == word.length()-1) {
        return;
    }
    string num = to_string(atoi(word.substr(num_start, num_end+1).c_str())+1);
    string newWord = word.substr(0, num_start) +
      num + word.substr(num_end+2);
    answ.push_back(newWord);
    
    this->_helper(newWord, num_start, num_start+num.length()-1, answ);
    
    for (int i = num_end + 2; i < word.length(); i++) {
        // insert 1 at i
        newWord = word.substr(0, i) + '1' + word.substr(i+1);
        answ.push_back(newWord);
        this->_helper(newWord, i, i, answ);
    }
}

const vector<string> _testcases = {
    "word",
    "a",
    "abba",
    "",
    "aaaaa",
};

int main(){
    Solution solve;
    for (string str : _testcases) {
        dzCommon::printArray(solve.generateAbbreviations(str), true);
    }
    return 0;
}