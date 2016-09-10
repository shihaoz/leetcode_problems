//
//  leetcode_valid_sudoku.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/7/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_valid_sudoku.hpp"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check_row[10], check_col[10];
        
        // check all rows, cols
        for (int i = 0; i < 9; i++) {
            memset(check_row, 0, sizeof(bool)*10);
            memset(check_col, 0, sizeof(bool)*10);
            for (int j = 0; j < 9; j++) {
                /// check row
                if (board[i][j] != '.') {
                    if (check_row[board[i][j] - '0']) {
                        return false;
                    }
                    check_row[board[i][j] - '0'] = true;
                }
                
                /// check column
                if (board[j][i] != '.') {
                    if (check_col[board[j][i] - '0']) {
                        return false;
                    }
                    check_col[board[j][i] - '0'] = true;
                }
            }
        }
        
        bool check_grid[10];
        for (int row1 = 0, row2 = 2; row1 < 9 and row2 < 9; row1 += 3, row2 += 3) {
            for (int col1 = 0, col2 = 2; col1 < 9 and col2 < 9; col1 += 3, col2 += 3) {
                // top-left (row1, col1) , bottom-right (row2, col2)
                memset(check_grid, 0, sizeof(bool)*10);
                for (int i = row1; i <= row2; i++) {
                    for (int j = col1; j <= col2; j++) {
                        if (board[i][j] != '.') {
                            if (check_grid[board[i][j] - '0']) {
                                return false;
                            }
                            check_grid[board[i][j] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Solution solve; cout << boolalpha;
    vector<vector<char>> grid1 = {
        {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
        {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '.', '.', '.', '.', '.', '.', '.', '.'},
    },
    grid2 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.',},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.',},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.',},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3',},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1',},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6',},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.',},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5',},
        {'9', '.', '.', '.', '8', '.', '.', '7', '9',},
    };
    
    cout << solve.isValidSudoku(grid1) << "\n";
    cout << solve.isValidSudoku(grid2) << "\n";
    return 0;
}