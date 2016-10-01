//
//  ms_linked_list_cycle.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_linked_list_cycle.hpp"

using namespace dzListNode;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast) {
            fast = fast->next;
            if (fast == slow) {
                return true;
            }
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return false;
    }
};