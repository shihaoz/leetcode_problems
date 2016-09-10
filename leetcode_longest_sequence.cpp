//
//  leetcode_longest_sequence.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/6/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_longest_sequence.hpp"
class Solution {
    int _helper_recursion(int num, unordered_set<int>& hash, int length);
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> _hash(nums.begin(), nums.end());

        int length = 0;
        while (!_hash.empty()) {
            int holder = 1, value = *_hash.begin();
            _hash.erase(_hash.begin());
            
            for (int i = value+1;
                 _hash.count(i);
                 i++) {
                holder++;   _hash.erase(i);
            }
            for (int i = value-1;
                 _hash.count(i);
                 i--) {
                holder++;   _hash.erase(i);
            }
            
            length = max(holder, length);
        }
        return length;
    }
};
int Solution::_helper_recursion(int num, unordered_set<int> &hash, int length){
    hash.erase(num);
    if (hash.find(num+1) != hash.end()) {
        length = this->_helper_recursion(num+1, hash, length+1);
    }
    if (hash.find(num-1) != hash.end()) {
        length = this->_helper_recursion(num-1, hash, length+1);
    }
    return length;
}
const vector<vector<int>> _testcases = {
    {100, 4, 200, 1, 3, 2},     // 4
    {1, 2, 5, 8, 100, 101, 99, 97, 98}, // 5
    {},                         // 0
    {1},                        // 1
    {-1, -2, 1, 0, 3,4,5,6},    // 4
};
int main(){
    Solution solve;
    
    for (vector<int> test : _testcases) {
        cout << solve.longestConsecutive(test) << "\n";
    }
    return 0;
}