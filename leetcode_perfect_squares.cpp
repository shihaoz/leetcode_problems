//
//  leetcode_perfect_squares.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/31/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_perfect_squares.hpp"

struct _TEST {
    int n;
};
const vector<_TEST> _testcases = {
    {12},
    {13},
    {25},
    {1},
    {2},
    {7},
    {31}
};

class Solution {
    int _helper_recursion(int n);
    int _helper_dp(int n);
public:
    int numSquares(int n) {
        return _helper_dp(n);
    }
};
int Solution::_helper_recursion(int n){
    if (n == 0) {
        return 0;
    }
    int min_sum = numeric_limits<int>::max();
    for (int i = 1; i*i <= n; i++) {
        min_sum = min(min_sum, this->_helper_recursion(n-i*i)+1);
    }
    return min_sum;
}
int Solution::_helper_dp(int n){
    // initialization
    static vector<int> _states(1, 0);
    int last_index = 1;
    if (n+1 > _states.size()) {
        last_index = _states.size();
        _states.resize(n+1, n);
        while (last_index < _states.size()) {
            for (int i = 1; i*i <= last_index; i++) {
                _states[last_index] = min(_states[last_index], _states[last_index - i*i]+1);
            }
            last_index++;
        }
    }

    return _states[n];
}


int main(){
    Solution solve;
    
    for (_TEST t : _testcases) {
        cout << t.n << ": " << solve.numSquares(t.n) << "\n";
    }
    cout << "1535" << ": " << solve.numSquares(1535) << "\n";
    return 0;
}