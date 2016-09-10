//
//  leetcode_bad_version.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/5/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_bad_version.hpp"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int bi_search(int left, int right){
        int save = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (isBadVersion(mid)) {
                save = mid; right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return save;
    }
    int firstBadVersion(int n) {
        if (isBadVersion(1)) {
            return 1;
        }
        int save = this->bi_search(1, n/2);
        if (save == -1) {
            return this->bi_search(n/2+1, n);
        }
        return save;
    }
};
