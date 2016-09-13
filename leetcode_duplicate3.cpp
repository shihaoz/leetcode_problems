//
//  leetcode_duplicate3.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/13/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_duplicate3.hpp"
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() or t < 0 or k < 0) {
            return false;
        }
        
        // set up
        // _tree <value, count>
        map<int, int> _tree;
        for (int i = 0; i < nums.size(); i++) {
            // check index distance
            if (i-k-1 >= 0) {
                if (_tree[nums[i-k-1]] == 1) {
                    _tree.erase(nums[i-k-1]);
                }
                else{
                    _tree[nums[i-k-1]]--;
                }
            }
            
            // store new
            _tree[nums[i]]++;
            map<int, int>::iterator it = _tree.find(nums[i]);
            
            if (it->second > 1) {
                return true;
            }
            if ((++it) != _tree.end()) {
                if (abs((long)it->first - (long)nums[i]) <= (long)t) {
                    return true;
                }
            }it--;
            if (it != _tree.begin()) {
                if ((long)abs((--it)->first - (long)nums[i]) <= (long)t) {
                    return true;
                }
            }
        
        }
        return false;
    }
};

struct TEST {
    vector<int> inputs;
    int k, t;
};

const vector<TEST> _testcases = {
    {
        {1, -5, 20, 10, 5, 0, 12}, 3, 3,    // true
    },
    {
        {1}, 3, 3,                  // false
    },
    {
        {1, 10, 3, 10, 2}, 2, 1,    // true
    },
    {
        {-1, -1}, 1, -1             // false
    },
    {
        {-1,2147483647}, 1, 2147483647  // false
    },
    {
        {1,2}, 0, 1             // false
    },
    {
        {1,3,1}, 1,1            // false
    }
};

int main(){
    Solution solve; cout << boolalpha;
    for (auto test : _testcases) {
        cout << solve.containsNearbyAlmostDuplicate(test.inputs, test.k, test.t) << "\n";
    }
    return 0;
}
