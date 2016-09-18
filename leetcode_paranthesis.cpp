//
//  leetcode_paranthesis.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/18/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_paranthesis.hpp"

class Solution {
    void _helper_recursion(int countLeft, int countRight, string paren, vector<string>& answ);
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        
        vector<vector<string>> now(n+1), next = now;
        now[n].push_back("");
        for (int left = n-1; left >= 0; left--) {
            for (int right = n; right >= left; right--) {
                int i = left+1, j = right;
                if (i <= n and i <= j) {
                    for (string str : now[right]) {
                        next[right].push_back(str + '(');
                    }
                }
                i = left, j = right+1;
                if (j <= n) {
                    for (string str : next[j]) {
                        next[right].push_back(str + ')');
                    }
                }
            }
            now = next; next = vector<vector<string>>(n+1);
        }
        return now.front();
    }
};

void Solution::_helper_recursion(int countLeft, int countRight, string paren, vector<string>& answ){
    if (countLeft + countRight == 0) {
        // both zero
        answ.push_back(paren);
    }
    else{
        if (countLeft > 0) {
            this->_helper_recursion(countLeft-1, countRight, paren+'(', answ);
        }
        if (countLeft < countRight) {
            this->_helper_recursion(countLeft, countRight-1, paren+')', answ);
        }
    }
}

const vector<int> _testcases = {
    3,
    4,
    2,
    5,
};

int main(){
    Solution solve;
    
    for (int i : _testcases) {
        dzCommon::printArray(solve.generateParenthesis(i), true);
        cout << dzCommon::seperator;
    }
    return 0;
}