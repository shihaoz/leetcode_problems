//
//  leetcode_matrix_zeros.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/24/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_matrix_zeros.hpp"


class Solution {
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        vector<bool> col(matrix[0].size(), false);
        for (int i = 0; i < matrix.size(); i++) {
            bool rowZero = false;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    col[j] = true;  rowZero = true;
                }
            }
            if (rowZero) {
                memset(matrix[i].data(), 0, sizeof(int)*matrix[i].size());
            }
        }
        for (int i = 0; i < col.size(); i++) {
            if (col[i]) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};

//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        if (matrix.empty()) {return;}
//        vector<bool> rows(matrix.size(), false), cols(matrix[0].size(), false);
//        for (int i = 0; i < rows.size(); i++) {
//            for (int j = 0; j < matrix[i].size() and !rows[i]; j++) {
//                if (matrix[i][j] == 0) {
//                    cols[j] = rows[i] = true;
//                }
//            }
//        }
//        for (int i = 0; i < cols.size(); i++) {
//            if (!cols[i]) {
//                for (int j = 0; j < matrix.size() and !cols[i]; j++) {
//                    if (matrix[j][i] == 0) {
//                        rows[j] = cols[i] = true;
//                    }
//                }
//            }
//        }
//        
//        for (int i = 0; i < rows.size(); i++) {
//            if (rows[i]) {
//                memset(matrix[i].data(), 0, sizeof(int)*matrix[i].size());
//            }
//        }
//        for (int i = 0; i < cols.size(); i++) {
//            if (cols[i]) {
//                for (int j = 0; j < matrix.size(); j++) {
//                    matrix[j][i] = 0;
//                }
//            }
//        }
//    }
//};
const vector<vector<vector<int>>> _testcases = {
    {
        {1, 0, 2, 3, 5},
        {0, 2, 3, 3, 3},
        {1, 2, 3, 4, 5},
        {3, 3, 3, 3, 0},
    },
    {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
    }
};
int main(){
    Solution solve;
    for (auto test : _testcases) {
        solve.setZeroes(test);
        dzCommon::printArrayArray(test, true);
    }
    return 0;
}