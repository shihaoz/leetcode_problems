//
//  fb_is_palindrome.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_is_palindrome.hpp"

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (!isalnum(s[left])) {left++;}
            else if(!isalnum(s[right])){right--;}
            else{
                if (tolower(s[left]) == tolower(s[right])) {
                    left++; right--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};