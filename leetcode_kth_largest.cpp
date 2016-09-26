//
//  leetcode_kth_largest.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_kth_largest.hpp"
class Solution {
/**
 way 1: use quick select; Time O(2n) and Space O(log(n)) or Space O(1) if use temporary storage;
 way 2: quick heap to keep track of k largest
 */
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) {
            return -1;
        }
        priority_queue<int, vector<int>, greater<int>> _min_heap;
        for (int i : nums) {
            _min_heap.push(i);
            if (_min_heap.size() > k) {
                _min_heap.pop();
            }
        }
        return _min_heap.top();
    }
};


struct TEST{
    vector<int> nums;
    int nth;
};
const vector<TEST> _testcases = {
    {
        {3,2,1,5,6,4},
        2,              // 5
    },
    {
        {5,4},
        1,
    },
    {
        {5},
        1,
    },
    {
        {5,5,5,4,4,4,3,3,6,6,},
        5,      // 5
    },
    {
        {},
        1,
    },
    {
        {6, -1, 7, -5},
        4,
    },
};

int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.findKthLargest(test.nums, test.nth) << "\n";
    }
    return 0;
}