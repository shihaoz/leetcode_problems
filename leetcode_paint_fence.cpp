//
//  leetcode_paint_fence.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_paint_fence.hpp"

class Solution {
public:
    int numWays(int n, int k) {
        int same = k, diff = k*(k-1);
        if (n == 1) {
            return k;
        }
        for (int i = 3; i <= n; i++) {
            int lastDiff = diff, lastSame = same;
            diff = (lastDiff + lastSame) * (k-1);
            same = lastDiff;
        }
        return same + diff;
    }
};

const vector<pair<int, int>> _testcases = {
    {3,3},
    {3,2},
    {1, 4},
    {2, 2},
};
int main(){
    Solution solve;
    for (auto test : _testcases) {
        cout << solve.numWays(test.first, test.second) << '\n';
    }
    return 0;
}