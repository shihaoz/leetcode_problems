//
//  leetcode_longest_common_substring.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/14/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_longest_common_substring.hpp"

void printArray(vector<vector<int>>& matrix){
    for (auto& vec : matrix) {
        for (int i : vec) {
            cout << i << " ";
        }cout << "\n";
    }cout << "---\n";
}
class Solution {
    
public:
    int longestCommonSubString(string a, string b);
    int longestCommonSubSequence(string a, string b);
    int longestPalindromicSubsequence(string a);
    int longestIncreasingSubsequence(vector<int>& vec);
    int editDistance(string a, string b);
    bool wordBreak(string target, vector<string>& words);
};
int Solution::longestCommonSubString(string a, string b) {
    // clean edge
    if (a.empty() or b.empty()) {
        return 0;
    }
    
    // setup
    int a_end = a.size()-1, b_end = b.size()-1;
    vector<vector<int>> _states(a.size() , vector<int>(b.size(), 0));
    /// results of a compare to last character of b
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[b_end]) {
            _states[i][b_end] += 1;
        }
    }
    /// results of b compare to last character of a
    for (int i = 0; i < b.size(); i++) {
        if (a[a_end] == b[i]) {
            _states[a_end][i] += 1;
        }
    }
    
    int answ = 0;
    for (int i = a_end-1; i >= 0; i--) {
        for (int j = b_end-1; j >= 0; j--) {
            if (a[i] == b[j]) {
                _states[i][j] += 1;
                _states[i][j] += _states[i+1][j+1];
                answ = max(answ, _states[i][j]);
            }
            else{
                _states[i][j] = 0;
            }
        }
    }
    return answ;
}
int Solution::longestCommonSubSequence(string a, string b) {
    if (a.empty() or b.empty()) {
        return 0;
    }
    // set up
    vector<vector<int>> _states(a.size(), vector<int>(b.size(), 0));
    int a_end = a.size()-1, b_end = b.size()-1;
    _states[a_end][b_end] = (a[a_end] == b[b_end]);
    /// initial setup
    for (int i = a_end, match = 0; i >= 0; i--) {
        if (a[i] == b[b_end]) {
            match = 1;
        }
        _states[i][b_end] = match;
    }
    /// initial setup
    for (int i = b_end, match = 0; i >= 0; i--) {
        if (b[i] == a[a_end]) {
            match = 1;
        }
        _states[a_end][i] = match;
    }
    
    for (int i = a_end-1; i >= 0; i--) {
        for (int j = b_end-1; j >= 0; j--) {
            _states[i][j] = max(_states[i+1][j+1] + (a[i]==b[j]),
                                max(_states[i][j+1], _states[i+1][j]));
        }
    }
    return _states[0][0];
}

int Solution::longestPalindromicSubsequence(string a){
    if (a.empty()) {
        return 0;
    }
    // setup
    vector<vector<int>> _states(a.size(), vector<int>(a.size(), 0));
    int a_end = a.size()-1;
    // diagnal all 1s
    for (int i = 0; i < a.size(); i++) {
        _states[i][i] = 1;
    }
    // dynamic programming
    for (int row = a_end-1; row >= 0; row--) {
        for (int j = row+1; j <= a_end; j++) {
            if (a[row] == a[j]) {
                _states[row][j] = _states[row+1][j-1] + 2;
            }
            else{
                _states[row][j] = max(_states[row][j-1], _states[row+1][j]);
            }
        }
    }
    return _states[0][a_end];
}

int Solution::longestIncreasingSubsequence(vector<int> &vec){
    if (vec.empty()) {
        return 0;
    }
    // setup
    int max_length = 0;
    vector<int> _states(vec.size(), 0);
    // build up
    for (int i = 0; i < _states.size(); i++) {
        int max_so_far = 0;
        for (int j = i-1; j >= 0; j--) {
            if (vec[j] <= vec[i]
                and
                _states[j] > max_so_far) {
                // find the max
                max_so_far = _states[j];
            }
        }
        _states[i] = max_so_far + 1;
        max_length = max(_states[i], max_length);
    }
    return max_length;
}

int Solution::editDistance(string a, string b){
    if (a.empty() or b.empty()) {
        return max(a.length(), b.length());
    }
    // setup
    int min_distance = numeric_limits<int>::max();
    vector<vector<int>> _states(a.size()+1, vector<int>(b.size()+1, 0));
    /// pad outside, where b is empty
    for (int i = 0; i <= a.length(); i++) {
        _states[i][b.size()] = a.length()-i;
    }
    /// pad outside, where a is empty
    for (int i = 0; i <= b.length(); i++) {
        _states[a.size()][i] = b.length()-i;
    }
    for (int i = a.size()-1; i >= 0; i--) {
        for (int j = b.size()-1; j >= 0; j--) {
            if (a[i] == b[j]) {
                _states[i][j] = _states[i+1][j+1];
            }
            else{
                _states[i][j] = min(_states[i+1][j+1], min(_states[i+1][j], _states[i][j+1])) + 1;
            }
        }
    }
    return _states[0][0];
}

bool Solution::wordBreak(string target, vector<string> &words){
    unordered_set<string> _lookup(words.begin(), words.end());
    if (target.empty() and _lookup.find("") == _lookup.end()) {
        return false;
    }
    // setup
    vector<bool> _states(target.size(), false);
    for (int i = 0; i < target.size(); i++) {
        if (_lookup.find(target.substr(0, i+1)) != _lookup.end()) {
            _states[i] = true;
        }
        else{
            // search j = 0->i-1
            for (int j = 0; j < i and !_states[i]; j++) {
                if (_states[j] and _lookup.find(target.substr(j+1, i-j)) != _lookup.end()) {
                    _states[i] = true;
                }
            }
        }
    }
    return _states.back();
}

const vector<pair<string, string>> _testcasesString = {
    {
        "abcdavidefg",
        "davidtozhang"
    },
    {
        "tutorialhorizon",
        "dynamictutorialProgramming"
    }
},
_testcasesSequence = {
    {
        "acbaed", "abcadf"
    },
    {
        "ACBDEA", "ABCDA"
    },
    {
        "ABCD", "AEBD",
    }
},
_testcasesEdit = {
    {
        "abc", "dbca"
    },
    {
        "horizon", "horizontal"
    },
    {
        "dbca", "bca"
    },
    {
        "edcba", "abcde",
    }
};
vector<string> _testcasesPalindrome = {
    "AABCDEBAZ",
    "AXABCDDCXXXXA",
    "ABDMMMCCMMDBAMM",
};
vector<vector<int>> _testcasesLIS = {
    { 1, 12, 7, 0, 23, 11, 52, 31, 61, 69, 70, 2 },
    {1, 5, 2, 0, -1, 3,  8}
};
vector<pair<string, vector<string>>> _testcasesWordBreak = {
    {
        "IamSumit", {"I" , "have", "Jain", "Sumit", "am", "this", "dog"}
    },
    {
        "thisisadog", {"I" , "have", "Jain", "Sumit", "am", "this", "dog"}
    },
    {
        "thisisdog", {"I", "is" , "have", "Jain", "Sumit", "am", "this", "dog"}
    },
    {
        "thisdoghavethis", {"I" , "have", "Jain", "Sumit", "am", "this", "dog"}
    }
};
int main(){
    Solution solve;
//    for (auto p : _testcasesString) {
//        cout << solve.longestCommonSubString(p.first, p.second) << "\n";
//    }
//    for (auto p : _testcasesSequence) {
//        cout << solve.longestCommonSubSequence(p.first, p.second) << "\n";
//    }
//    for (string s : _testcasesPalindrome) {
//        cout << solve.longestPalindromicSubsequence(s) << "\n";
//    }
//    for (vector<int> test : _testcasesLIS) {
//        cout << solve.longestIncreasingSubsequence(test) << "\n";
//    }
//    for (auto test : _testcasesEdit) {
//        cout << solve.editDistance(test.first, test.second) << "\n";
//    }
    cout << boolalpha;
    for (auto test : _testcasesWordBreak) {
        cout << solve.wordBreak(test.first, test.second) << "\n";
    }
    return 0;
}