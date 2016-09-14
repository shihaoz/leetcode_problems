//
//  leetcode_sliding_window_max.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/13/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_sliding_window_max.hpp"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> _answ, _maxes(nums.size(), 0);  int left = 0, right = -1;
        for (int i = 0; i < nums.size(); i++) {
            /// left = current max, right = right end index (inclusive)
            // pop if i+1 >= k
            if (i+1 > k) {
                int to_pop = nums[i-k];
                if (to_pop == _maxes[left]) {
                    left++;
                }
            }
            
            
            while (right >= left and _maxes[right] < nums[i]) {
                // push this number in
                right--;
            }
            /// right is at left-- (which means empty) or _maxes[right] >= nums[i]
            _maxes[++right] = nums[i];
            if (i >= k-1) {
                _answ.push_back(_maxes[left]);
            }
        }
        return _answ;
    }
};
struct TEST {
    vector<int> inputs;
    int k;
};
const vector<TEST> _testcases = {
    {
        {1, 2, 3, 4, 5}, 3,
    },
    {
        {1,3,-1,-3,5,3,6,7}, 3
    },
    {
        {-1, -2, -3, -4, -5}, 2
    },
    {
        {}, 5
    },
    {
        {-1, 10, -3, 8, -5}, 2
    },
};
void printArray(vector<int> vec){
    for (int i : vec) {
        cout << i << " ";
    }cout << "\n";
}
int main(){
    Solution solve;
    for (TEST test : _testcases) {
        printArray(solve.maxSlidingWindow(test.inputs, test.k));
    }
    return 0;
}