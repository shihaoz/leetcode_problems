//
//  ms_reverse_ll.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/26/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_reverse_ll.hpp"

using namespace dzListNode;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *now = head, *next = nullptr;
        while (now) {
            next = now->next;   // record next
            now->next = prev;   // point backward
            prev = now; now = next; // move up the chain
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *rev_before = nullptr, *rev_head = head, *rev_tail, *rev_after = nullptr;
        for (int i = 0; i < m-1; i++) {
            rev_before = rev_head;
            rev_head = rev_before->next;
        }
        rev_tail = rev_head;
        for (int i = m; i < n; i++) {
            rev_tail = rev_tail->next;
        }
        rev_after = rev_tail->next;
        // setup for our reverse
        rev_tail->next = nullptr;
        this->reverseList(rev_head);
        
        // connect
        if (rev_before) {
            rev_before->next =rev_tail;
        }
        else{// if no element before rev_head, rev_tail becomes the head
            head = rev_tail;
        }
        rev_head->next = rev_after;
        return head;
    }
};

struct TEST2{
    vector<int> inputs;
    int start, end;
};
const vector<vector<int>> _testcases1 = {
    {1,2,3,4,5,},
    {},
    {1},
    {1,2,3,3,3,4},
};
const vector<TEST2> _testcases2 = {
    {
        {1,2,3,4,5,},
        2,5,
    },
    {
        {1,2,3,3,3,4},
        1,6,
    },
    {
        {1,2,3,4,},
        1,1,
    },
    {
        {1,2,3,4,},
        1,3,
    },
    {
        {1,2,3},
        2,3,
    }
};


int main(){
    Solution solve;
    
//    for (auto test : _testcases) {
//        ListNode* head = dzListNode::buildList(test);
//        head = solve.reverseList(head);
//        dzListNode::printList(head);
//        dzListNode::clearList(head);
//    }
    for (auto test : _testcases2) {
        ListNode* head = dzListNode::buildList(test.inputs);
        head = solve.reverseBetween(head, test.start, test.end);
        dzListNode::printList(head);
        dzListNode::clearList(head);
    }
    return 0;
}