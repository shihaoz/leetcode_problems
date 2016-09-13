//
//  palindrome_pairs.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/11/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "palindrome_pairs.hpp"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
        }
        for(int i = 0; i < words.size(); i++) {
            string wd_rev = words[i];   reverse(wd_rev.begin(), wd_rev.end());
            for(int j = 0; j <= words[i].length(); j++) {
                string rev_part = wd_rev.substr(words[i].length() - j);
                if (dict.count(rev_part) and dict[rev_part] != i) {
                    if (is_palindrome(words[i], j, words.size()-1)) {
                        result.push_back({i, dict[rev_part]});
                    }
                }
                rev_part = wd_rev.substr(0, wd_rev.size() - j);
                if(j > 0 and dict.count(rev_part) and dict[rev_part] != i) {
                    if (is_palindrome(words[i], 0, j-1)) {
                        result.push_back({dict[rev_part], i});
                    }
                }
            }
        }
        return result;
    }
    
    bool is_palindrome(string& s, int start, int end) {
        while(start < end and s[start] == s[end]) {
            start++;    end--;
        }
        return start >= end;
    }
};

const vector<vector<string>> _testcases = {
    {
        "bat", "tab", "cat"     //  (0,1) (1,0)
    },
    {
        "bat", "tab", "cat", "ac"   // (0,1) (1,0) (2,3)
    },
    {
        "abcd", "dcba", "lls", "s", "sssll" //[[0, 1], [1, 0], [3, 2], [2, 4]]
    },
    {
        "a",""  // [0,1] [1,0]
    }
};
void printPairs(vector<vector<int>> in){
    for (vector<int>& vec : in) {
        cout << "(" << vec[0] << ", " << vec[1] << ") ";
    }cout << "\n";
}
int main(){
    Solution solve;
    
    for (vector<string> vec : _testcases) {
        printPairs(solve.palindromePairs(vec));
    }
    return 0;
}