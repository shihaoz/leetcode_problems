//
//  airbnb_palindrome_pair.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "airbnb_palindrome_pair.hpp"

class Solution {
    bool _isPalindrome(string word, int left, int right);
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> mapIdx;
        for (int i = 0; i < words.size(); i++) {
            mapIdx[words[i]] = i;
        }
        /// empty words or whole reverse word
        for (int i = 0; i < words.size(); i++) {
            string hold = words[i]; reverse(hold.begin(), hold.end());
            if (words[i].empty()) {
                for (int j = 0; j < words.size(); j++) {
                    if (i != j and _isPalindrome(words[j], 0, words[j].size()-1)) {
                        result.push_back({i, j});   result.push_back({j, i});
                    }
                }
            }
            else if(mapIdx.find(hold) != mapIdx.end() and mapIdx[hold] != i){
                result.push_back({i, mapIdx[hold]});
            }
        }
        /// [0:cut] is palindrome, find reverse([cut+1:])
        for (int i = 0; i < words.size(); i++) {
            for (int cut = 0; cut < (int)words[i].size()-1; cut++) {
                if (_isPalindrome(words[i], 0, cut)) {
                    string target = words[i].substr(cut+1); reverse(target.begin(), target.end());
                    if (mapIdx.find(target) != mapIdx.end()) {
                        result.push_back({mapIdx[target], i});
                    }
                }
            }
        }
        /// [cut:] is palindrome, find reverse( [0:cut-1] )
        for (int i = 0; i < words.size(); i++) {
            for (int cut = 1; cut < (int)words[i].size(); cut++) {
                if (_isPalindrome(words[i], cut, words[i].size()-1)) {
                    string target = words[i].substr(0, cut);    reverse(target.begin(), target.end());
                    if (mapIdx.find(target) != mapIdx.end()) {
                        result.push_back({i, mapIdx[target]});                      }
                }
            }
        }
        return result;
    }
};

bool Solution::_isPalindrome(string word, int left, int right){
    while (left < right and word[left] == word[right]) {
        left++; right--;
    }
    return left >= right;
}

const vector<vector<string>> _testcases = {
    {"abcd", "dcba", "lls", "s", "sssll"},
    {"bat", "tab", "cat"},
    {"a", ""},
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        dzCommon::printArrayArray(solve.palindromePairs(test), true);
    }
    return 0;
}