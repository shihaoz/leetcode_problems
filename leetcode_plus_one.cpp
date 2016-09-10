//
//  leetcode_plus_one.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/28/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_plus_one.hpp"
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return digits;
        }
        else if (digits.back() != 9){
            digits.back() += 1;
        }
        else{
            auto it = digits.rbegin();
            *it++ = 0;
            while (it != digits.rend() and *it == 9) {
                *it++ = 0;
            }
            if (it == digits.rend()) {  // if all 9s
                digits.insert(digits.begin(), 1);
            }
            else{   // if not all 9s
                *it += 1;
            }
        }
        for (auto i : digits) {
            cout << i << " ";
        }cout << "\n";
        return digits;
    }
};


int main(){
    Solution solve;
    vector<int> inputs;
    
    inputs = {1, 2, 3, 4, 9};
    solve.plusOne(inputs);
    
    inputs = {0, 1, 9, 9};
    solve.plusOne(inputs);
    
    inputs = {9, 9, 9, 9};
    solve.plusOne(inputs);
    return 0;
}