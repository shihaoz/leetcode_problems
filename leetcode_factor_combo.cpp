//
//  leetcode_factor_combo.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_factor_combo.hpp"
class Solution {
private:
    vector<vector<int>> answ;
public:
    vector<vector<int>> getFactors(int n) {
        this->_helper(n, 2, {});
        return answ;
    }
    /**
     @input:
        n: target value
        bottom: first value to search for
        line: result so far
     */
    void _helper(int target, int start, vector<int> result){
        for (int i = start; i <= sqrt(target); i++) {
            if (target % i) {// not divisible
                continue;
            }
            // divisible
            vector<int> newResult = result;
            newResult.push_back(i);
            this->_helper(target/i, i, newResult);
            newResult.push_back(target/i);
            this->answ.push_back(newResult);
        }
    }
};

const vector<int> _testcases = {
    8,
    12,
    16,
};

int main(){
    Solution solve;
    
    
    for (auto test : _testcases) {
        dzCommon::printArrayArray(solve.getFactors(test), true);
    }
    return 0;
}