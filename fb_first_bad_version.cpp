//
//  fb_first_bad_version.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_first_bad_version.hpp"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)){return 1;}
        int last_pos = n;
        int left = 1, right = n;
        while (left <= right) {
            int mid = (left+right)/2;
            if (isBadVersion(mid)) {
                right = mid-1;  last_pos = mid;
            }
            else{
                left = mid+1;
            }
        }
        return last_pos;
    }
};


int main(){
    
    return 0;
}