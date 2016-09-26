//
//  leetcode_shortest_word3.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_shortest_word3.hpp"


class Solution {
    
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int min_distance = numeric_limits<int>::max();
        int word1_idx = -1*words.size(), word2_idx = -1*words.size();
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                if (word1 == word2) {
                    word2_idx = word1_idx;
                }
                word1_idx = i;
                min_distance = min(min_distance, word1_idx - word2_idx);
            }
            else if(words[i] == word2) {
                word2_idx = i;
                min_distance = min(min_distance, word2_idx - word1_idx);
            }
        }
        return min_distance;
    }
};

struct TEST{
    vector<string> words;
    string word1, word2;
};

const vector<TEST> _testcases = {
    {
        {"practice", "makes", "perfect", "coding", "makes"},
        "coding","practice",
    },
    {
        {"practice", "makes", "perfect", "coding", "makes"},
        "makes","makes",
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.shortestWordDistance(test.words, test.word1, test.word2) << "\n";
    }
    return 0;
}