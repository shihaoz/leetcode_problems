//
//  leetcode_min_window_sub.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/13/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_min_window_sub.hpp"



class Solution {

public:
    string minWindow(string s, string t) {
        if (t.empty()) {
            return "";
        }
        string window = s;
        unordered_map<char, int> t_count, s_count;
        for (char c : t) {
            t_count[c]++;
        }
        
        int left = 0, right = 0, remain_element = t_count.size();
        while (right < s.size() and remain_element > 0) {
            if (t_count.find(s[right]) != t_count.end()) {
                t_count[s[right]]--;
                remain_element -= (t_count[s[right]] == 0);
            }
            right++;
        }
        right--;
        if (remain_element > 0) {
            // cannot find all
            return "";
        }
        /// left points at 0, right points at last character needed
        while (right < s.size()) {
            while (t_count.find(s[left]) == t_count.end()
                   or
                   t_count[s[left]]++ < 0) {
                // useless or extra character
                left++;
            }
            /// left == first important character
            t_count[s[left]]--;
            // update minimum-window
            if (right-left+1 < window.size()) {
                window = s.substr(left, right-left+1);
            }
            /// search for next character
            char to_find = s[left++];   right++;
            while (right < s.size() and s[right] != to_find) {
                if (t_count.find(s[right]) != t_count.end()) {
                    t_count[s[right]]--;
                }
                right++;
            }
        }
        return window;
    }
};

const vector<pair<string, string>> _testcases = {
    make_pair("ADOBECODEBANC", "ABC"),
    make_pair("abcdcdca", "cdac"),
    make_pair("", "abc"),
    make_pair("abcasdas", "a"),
};

int main(){
    Solution solve;
    for (auto p : _testcases) {
        cout << solve.minWindow(p.first, p.second) << "\n";
    }
    return 0;
}