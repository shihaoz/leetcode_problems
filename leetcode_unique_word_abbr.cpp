//
//  leetcode_unique_word_abbr.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/31/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_unique_word_abbr.hpp"

class ValidWordAbbr {
    
    unordered_map<string, int> _abbr;
    unordered_set<string> _words;
    string _processWord(string word){
        string hold = word[0]
        + ((word.size() > 2) ? (to_string(word.size()-2)) : (""))
        + word[word.size()-1];
        return hold;
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto wd : dictionary) {
            this->_words.insert(wd);
        }
        
        for (auto it = this->_words.begin(); it != this->_words.end(); it++) {
            this->_abbr[this->_processWord(*it)]++;
        }
    }
    
    bool isUnique(string word) {
        return this->_abbr[this->_processWord(word)] ==
        ((this->_words.find(word) == this->_words.end()) ? 0 : 1);
    }
};

int main(){
    vector<string> inputs;
    inputs = { "deer", "door", "cake", "coe", "hello", "hello"};
    ValidWordAbbr solve(inputs);
    
    cout << boolalpha;
    
    cout << solve.isUnique("dear") << "\n";
    cout << solve.isUnique("cart") << "\n";
    cout << solve.isUnique("cane") << "\n";
    cout << solve.isUnique("make") << "\n";
    cout << solve.isUnique("hello") << "\n";
    cout << solve.isUnique("cake") << "\n";
    return 0;
}
