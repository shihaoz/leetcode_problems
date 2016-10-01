//
//  ms_merge_sorted_array.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/26/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_merge_sorted_array.hpp"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        int idx1 = m-1, idx2 = n-1, put_back = m+n-1;
        while (idx1 >= 0 and idx2 >= 0) {
            if (nums1[idx1] > nums2[idx2]) {
                nums1[put_back--] = nums1[idx1--];
            }
            else{
                nums1[put_back--] = nums2[idx2--];
            }
        }
        while (idx2 >= 0) {
            nums1[put_back--] = nums2[idx2--];
        }
    }
};

const vector<pair<vector<int>, vector<int>>> _testcases = {
    {
        {1,2,3,8,},
        {4, 5, 9,},
    },
    {
        {1},
        {0},
    },
    {
        {1,2,3,4,},
        {},
    },
    {
        {6,7,8},
        {1,2,},
    },
    {
        {},
        {},
    },
};

int main(){
    Solution solve;
    
    for (auto test : _testcases) {
        solve.merge(test.first, test.first.size(), test.second, test.second.size());
        dzCommon::printArray(test.first);
    }
    return 0;
}