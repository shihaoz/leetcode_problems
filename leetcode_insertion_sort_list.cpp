//
//  leetcode_insertion_sort_list.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/23/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_insertion_sort_list.hpp"
using namespace dzListNode;
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head or !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);   dummy->next = head;
        for (ListNode* now = head->next, *nowPrev = head;
             now != nullptr;
             now = nowPrev->next) {
            if (now->val > nowPrev->val) {
                nowPrev = nowPrev->next;
            }
            else{
                int tmp = now->val;
                ListNode* check = dummy;
                // find position
                while (check->next->val < tmp) {
                    check = check->next;
                }
                // start moving
                nowPrev->next = now->next;
                now->next = check->next;
                check->next = now;
                
            }
        }
        return dummy->next;
    }
};

const vector<vector<int>> _testcases = {
    {
        6, 5, 3, 1, 8, 7,
    },
    {
    },
    {
        1, 5,
    },
    {
        5, 1
    },
    {
        -2147483647,-2147483648
    },
};

int main(){
    Solution solve;
    
    for (vector<int> vec : _testcases) {
        printList(solve.insertionSortList(buildList(vec)));
    }
    return 0;
}
