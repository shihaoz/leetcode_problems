//
//  leetcode_substring_all_words.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/13/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_substring_all_words.hpp"
bool cmp(string a, string b){
    return a.size() > b.size();
}
class Solution {
    
public:
    static bool _helper(string s, int left, int right, vector<string>& words);
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answ;
        // setup
        sort(words.begin(), words.end(), cmp);
        int total_length = 0;
        for (string wd: words) {
            total_length += wd.length();
        }
        
        // sliding window
        for (int i = 0, j = i + total_length - 1; j < s.size(); i++,j++) {
            if (this->_helper(s, i, j, words)) {
                answ.push_back(i);
            }
        }
        return answ;
    }
};
bool Solution::_helper(string s, int left, int right, vector<string> &words){
    // words are sorted based on size, largest first
    vector<pair<int, int>> _ranges(1, make_pair(left, right));
    for (string wd : words) {
        bool found = false;
        for (int i = 0; i < _ranges.size() and found == false; i++) {
            pair<int, int> range = _ranges[i];
            int idx = s.substr(range.first, range.second+1).find(wd);
            if (idx == string::npos) {
                // do nothing
            }
            else{
                idx += range.first;
                found = true;
                int end = idx + wd.size();  // one past final word
                if (idx == range.first and end == range.second+1) {
                    // this range covers the entire word
                    _ranges.erase(_ranges.begin() + i);
                }
                // modify current range
                else if(idx == range.first){
                    _ranges[i].first = end;
                }
                else if(end == range.second+1){
                    _ranges[i].second = idx-1;
                }
                else{
                    // range becomes -> (range.first, idx-1) (end, range.second)
                    _ranges.emplace_back(end, _ranges[i].second);
                    _ranges[i].second = idx-1;
                }
            }
        }
        if (!found) {
            return false;
        }
    }
    return _ranges.empty();
}
struct TEST {
    vector<string> words;
    string s;
};
const vector<TEST> _testcases = {
    {
        {"ab", "ba", "ba", }, "ababaab",
    },
    {
        {"foo", "bar"}, "barfoothefoobarman",
    },
    {
        {"bar","foo","the"}, "barfoofoobarthefoobarman"
    }
};
void printArray(vector<int> vec){
    for (int i : vec) {
        cout << i << " ";
    }cout << "\n";
}
int main(){
    Solution solve;
    for (auto test : _testcases) {
        printArray(solve.findSubstring(test.s, test.words));
    }
    return 0;
}