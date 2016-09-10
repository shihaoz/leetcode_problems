//
//  leetcode_range_sum_query.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/6/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_range_sum_query.hpp"

class NumMatrix {
    vector<vector<int>> _range_sum, * _matrix;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        _matrix = &matrix;
        _range_sum = vector<vector<int>>(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            _range_sum[i].reserve(matrix[i].size());
            
            for (int j = 0, sum = 0; j < matrix[i].size(); j++) {
                sum += matrix[i][j];
                _range_sum[i].push_back(sum);
            }
        }
    }
    
    void update(int row, int col, int val) {
        if (row >= 0 and row < this->_range_sum.size()
            and
            col >= 0 and col < this->_range_sum.front().size()) {
            int diff = val - (*this->_matrix)[row][col];
            for (int j = col; j < this->_range_sum[row].size(); j++) {
                this->_range_sum[row][j] += diff;
            }
            (*this->_matrix)[row][col] = val;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += this->_range_sum[i][col2] - ((col1 == 0) ? 0:this->_range_sum[i][col1-1]);
        }
        return sum;
    }
};
struct TEST {
    vector<vector<int>> matrix;
    vector<int> update;         // size == 3
    vector<int> query;          // size == 4
};

const vector<TEST> _testcases = {
    {{
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    },
        {3, 2, 2},
        {2, 1, 4, 3}
    },
    {{
        {1}
    },
        {0,0,-1},
        {0,0,0,0}
    },
};
int main(){
    
    for (auto test : _testcases) {
        NumMatrix solve(test.matrix);
        cout << solve.sumRegion(test.query[0], test.query[1], test.query[2], test.query[3]) << "\n";
        solve.update(test.update[0], test.update[1], test.update[2]);
        cout << solve.sumRegion(test.query[0], test.query[1], test.query[2], test.query[3]) << "\n";
    }
    vector<vector<int>> matrix = {
        {2, 4},
        {-3, 5},
    };
    NumMatrix solve(matrix);
    solve.update(0, 1, 3);
    solve.update(1, 1, -3);
    solve.update(0, 1, 1);
    cout << solve.sumRegion(0, 0, 1, 1) << "\n";
    return 0;
}