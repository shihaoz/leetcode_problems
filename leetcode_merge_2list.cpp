//
//  leetcode_merge_2list.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/23/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_merge_2list.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /**
         merge two sorted linked list
         */
        ListNode dummy(-1), *head = &dummy, *last = head;
        while (l1 and l2) {
            if (l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
            }
            else{
                last->next = l2;
                l2 = l2->next;
            }
            last = last->next;
        }
        if (l1) {
            last->next = l1;
        }
        if (l2) {
            last->next = l2;
        }
        return head->next;
    }
};