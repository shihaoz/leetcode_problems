//
//  leetcode_find_nth_element.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_find_nth_element.hpp"

class Solution{
public:
    /**
     @left,right [left, right] inclusive
     @nums: numbers 
     @nth: the idx element to be found
     */
    void _helper(int left, int right, vector<int>& nums, int nth);
    /**
     @left, right [left, right] inclusive
     @nums: numbers
     @return: use [right] element as pivot, return pivot index
     */
    int _partition(int left, int right, vector<int>& nums);
    void nth_element(vector<int>& nums, int nth);
};
void Solution::nth_element(vector<int> &nums, int nth){
    this->_helper(0, nums.size()-1, nums, nth);
}

void Solution::_helper(int left, int right, vector<int> &nums, int nth){
    if(right - left <= 2){
        assert((nth >= left) and (nth <= right));
        sort(nums.begin()+left, nums.begin()+right+1);
        return;
    }
    // partition
    int pivot = this->_partition(left, right, nums);
    if (pivot == nth) {
        return;
    }
    else if(pivot < nth){
        this->_helper(pivot+1, right, nums, nth);
    }
    else{
        this->_helper(left, pivot-1, nums, nth);
    }
}
int Solution::_partition(int left, int right, vector<int> &nums){
    int pivot = right;
    right -= 1;
    while (left <= right) {
        if (nums[left] < nums[pivot]) { // push left to >= pivot
            left++;
        }
        else if (nums[right] >= nums[pivot]){   // push right to < pivot
            right--;
        }
        else{   // ready to swap
            swap(nums[left++], nums[right--]);
        }
    }
    swap(nums[left], nums[pivot]);
    return left;
}

struct TEST_PARTITION{
    int left, right;
    vector<int> nums;
};
const vector<TEST_PARTITION> _testcases_partition = {
    {
        0,1,
        {5, 3},
    },
    {
        0, 5,
        {5, 3, 8, 9, 1, 6,}
    },
    {
        0, 6,
        {5, 5, 5, 5, 4, 6, 5},
    }
};

struct TEST_NTH{
    vector<int> nums;
    int nth;
};
const vector<TEST_NTH> _testcases_nth = {
    {
        {5, 10, 5, 18, 9, 2},
        4,
    },
    {
        {9,8,7,6,5,4,3,2,1},
        4,
    },
    {
        {3,2,1,5,6,4,},
        4,
    },
};

int main(){
    Solution solve;
//    cout << "testing partition: \n";
//    for (auto test : _testcases_partition) {
//        cout << solve._partition(test.left, test.right, test.nums) << "\n";
//        dzCommon::printArray(test.nums, true);
//    }
//    dzCommon::printSeparator();

    for (auto test : _testcases_nth) {
        solve.nth_element(test.nums, test.nth);
        cout << test.nth << "th element:\n";
        dzCommon::printArray(test.nums, true);
        dzCommon::printSeparator('-');
    }
    return 0;
}