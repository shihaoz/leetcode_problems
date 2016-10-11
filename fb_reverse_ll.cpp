//
//  fb_reverse_ll.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_reverse_ll.hpp"
using namespace dzListNode;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *last = nullptr, *now = head, *next = nullptr;
        while (head) {
            next = head->next;  // hold
            head->next = last;
            last = head;    head = next;
        }
        return last;
    }
};