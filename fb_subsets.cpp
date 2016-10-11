//
//  fb_subsets.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_subsets.hpp"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> _answ; _answ.push_back({});
        for (int num_now : nums) {
            int size = _answ.size();
            for (int i = 0; i < size; i++) {
                _answ.push_back(_answ[i]);  _answ.back().push_back(num_now);
            }
        }
        return _answ;
    }
};