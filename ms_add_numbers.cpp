//
//  ms_add_numbers.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_add_numbers.hpp"
using namespace dzListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *last = dummy;
        int carryBit = 0;
        while (l1 and l2) {
            ListNode* newNode = new ListNode((carryBit + l1->val + l2->val)%10);
            carryBit = (carryBit + l1->val + l2->val)/10;
            last->next = newNode;
            last = newNode;
            l1 = l1->next;  l2 = l2->next;
        }
        ListNode *remain = (l1) ? l1:l2;
        while (remain) {
            ListNode* newNode = new ListNode((carryBit + remain->val)%10);
            carryBit = (carryBit + remain->val)/10;
            last->next = newNode;
            last = newNode;
            remain = remain->next;
        }
        if (carryBit) {
            ListNode *newNode = new ListNode(1);
            last->next = newNode;
        }
        return dummy->next;
    }
};
const vector<pair<vector<int>, vector<int>>> _testcases = {
    {
        {1,2,3,4,5},
        {6,5,8,5,},
    },
    {
        {5},
        {5},
    },
};
int main(){
    Solution solve;
    for (auto test : _testcases) {
        ListNode* l1 = dzListNode::buildList(test.first),
            *l2 = dzListNode::buildList(test.second);
        ListNode *ret = solve.addTwoNumbers(l1, l2);
        dzListNode::printList(ret);
        dzListNode::clearList(ret);
    }
    return 0;
}