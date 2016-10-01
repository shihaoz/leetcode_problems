//
//  google_reverse_vowel.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "google_reverse_vowel.hpp"


class Solution {
    unordered_set<char> _vowels = {
        'a', 'e', 'i', 'o', 'u',
        'A', 'E', 'I', 'O', 'U',
    };
    bool _isVowel(char c){
        return this->_vowels.find(c) != this->_vowels.end();
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (!this->_isVowel(s[i])) {    // move to a vowel
                i++;
            }
            else if(!this->_isVowel(s[j])){ // move to a vowel
                j--;
            }
            else{
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

const vector<string> _testcases = {
    "leetcode",
    "hello",
    "aeiou",
    "aA",
    "DaviD",
};

int main(){
    Solution solve;
    for (string test : _testcases) {
        cout << solve.reverseVowels(test) << '\n';
    }
    return 0;
}