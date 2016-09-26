//
//  leetcode_shortest_word2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_shortest_word2.hpp"

class WordDistance {
    /**
     try 1: direct caching + pre-compute distance of 1,2 
     constructor: Time O(n)
     query: hit --> O(1), 
            miss --> O(n),
     
        result: TLE;
     
    
     */
    unordered_map<string, vector<int>> _lookup;
    
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            _lookup[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int min_distance = numeric_limits<int>::max();
        if (word1 != word2) {
            auto it_left = _lookup[word1].begin(), it_right = _lookup[word2].begin(),
            left_end = _lookup[word1].end(), right_end = _lookup[word2].end();
            while (it_left != left_end and it_right != right_end) {
                if (*it_left < *it_right) { // it_left smaller
                    min_distance = min(*it_right - *it_left, min_distance);
                    it_left++;
                }
                else{   // it_right smaller
                    min_distance = min(*it_left - *it_right, min_distance);
                    it_right++;
                }
            }
        }
        else{   /// same word
            for (int i = 0; i < _lookup[word1].size()-1; i++) {
                min_distance = min(min_distance, _lookup[word1][i+1]-_lookup[word1][i]);
            }
        }
        
        return min_distance;
    }
    
};

struct TEST{
    vector<string> words;
    vector<pair<string, string>> querys;
};

const vector<TEST> _testcases = {
    {
        {"practice", "makes", "perfect", "coding", "makes"},
        {
            {"coding","practice"},
            {"makes", "coding"},
            {"perfect", "makes"},
            {"makes","makes"},
        }
    },
};

int main(){
    
    for (auto test : _testcases) {
        WordDistance solve(test.words);
        for (pair<string, string> q : test.querys) {
            cout << solve.shortest(q.first, q.second) << '\n';
        }
    }
    return 0;
}