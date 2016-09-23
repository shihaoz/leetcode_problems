//
//  fb_sort_color.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/22/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_sort_color.hpp"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3, 0);
        for (int i : nums) {
            colors[i] ++;
        }
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < colors[i]; j++, idx++) {
                nums[idx] = i;
            }
        }
    }
    void sortColors2(vector<int>& nums){
        if (nums.size() <= 1) {
            return;
        }
        int a = 0, b = 0, c = nums.size()-1;
        while(b <= c){
            if (nums[b] == 0) {
                swap(nums[a], nums[b]);
                a++;    b++;
            }
            else if (nums[b] == 1){
                b++;
            }
            else{
                swap(nums[b], nums[c]);
                c--;
            }
        }
    }
};

const vector<vector<int>> _testcases = {
    {0, 1, 2, 2, 1, 2, 2,},
    {0, 1, 2, 0, 1, 1, 1,},
    {2},
    {1},
    {1,0},
    {},
};

int main(){
    Solution solve;
    
    for (vector<int> vec : _testcases) {
        solve.sortColors2(vec);
        dzCommon::printArray(vec);
    }
    return 0;
}