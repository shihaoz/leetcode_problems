//
//  leetcode_wiggle_sort.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/23/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_wiggle_sort.hpp"

class Solution {
    bool isEven(int num){
        return num%2 == 0;
    }
public:
    void wiggleSort(vector<int>& nums) {
        
        for (int i = 0; i < (int)nums.size()-1; i++) {
            if (this->isEven(i) and nums[i] > nums[i+1]) {
                // [i] <= [i+1]
                swap(nums[i], nums[i+1]);
            }
            else if(!this->isEven(i) and nums[i] < nums[i+1]) {
                // [i] >= [i+1]
                swap(nums[i], nums[i+1]);
            }
        }
    }
};


const vector<vector<int>> _testcases = {
    {
        3,5,2,1,8,7
    },
    {
        3,
    },
    {
        
    },
    {
        1,2,3,4,5,6,7,
    }
};

int main(){
    Solution solve;
    for (vector<int> vec : _testcases) {
        solve.wiggleSort(vec);
        dzCommon::printArray(vec);
    }
    return 0;
}