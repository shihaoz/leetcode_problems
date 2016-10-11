//
//  fb_group_anagram.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_group_anagram.hpp"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answ;
        int idx = 0;
        unordered_map<string, int> mappings;
        for (string s : strs) {
            string tmp = s; sort(s.begin(), s.end());
            if (mappings.find(s) == mappings.end()) {// never seen before
                answ.push_back({});
                mappings[s] = idx++;
            }
            answ[mappings[s]].push_back(tmp);
        }
        return answ;
    }
};
const vector<vector<string>> _testcases = {
    {
        "eat", "tea", "tan", "ate", "nat", "bat",
    },
    {
        "cba","abc",
    },
    {
        
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        dzCommon::printArrayArray(solve.groupAnagrams(test), true);
    }
    return 0;
}