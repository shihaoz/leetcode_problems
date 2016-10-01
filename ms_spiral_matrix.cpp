//
//  ms_spiral_matrix.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_spiral_matrix.hpp"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answ;
        
        if (!matrix.empty()) {
            answ.reserve(matrix.size() * matrix.front().size());
            
            int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
            while (left <= right and top <= bottom) {
                if (left == right) {/// single colum
                    for (int i = left, j = top; j <= bottom; j++) {
                        answ.push_back(matrix[j][i]);
                    }
                }
                else if(top == bottom){/// single row
                    for (int i = left, j = top; i <= right; i++) {
                        answ.push_back(matrix[j][i]);
                    }
                }
                else{
                    for (int i = left, j = top; i <= right; i++) {  // top left->right
                        answ.push_back(matrix[j][i]);
                    }
                    for (int i = right, j = top+1; j <= bottom; j++) {    // right top->bottom
                        answ.push_back(matrix[j][i]);
                    }
                    for (int i = right-1, j = bottom; i >= left; i--) {   // bottom right->left
                        answ.push_back(matrix[j][i]);
                    }
                    for (int i = left, j = bottom-1; j >= top+1; j--) { // left bottom->top
                        answ.push_back(matrix[j][i]);
                    }
                }
                left++; right--;  top++;  bottom--;
            }
        }
        return answ;
    }
};

const vector<vector<vector<int>>> _testcases = {
    {
        {1,2,3,4,5},
        {1,2,3,4,5},
    },
    {
        {1,2,3,4,5},
    },
    {
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},
    },
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    },
    {
        {1}
    },
    {
        {}
    },
    {
        {1},
        {2},
        {3},
        {4},
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        dzCommon::printArray(solve.spiralOrder(test), true);
    }
    return 0;
}