//
//  fb_sort_list.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/22/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_sort_list.hpp"

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    ListNode* mergeHelper(ListNode* left, ListNode* right);
public:
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) { // 1 or 0 element
            return head;
        }
        ListNode *mid = head, *tail = head;
        while (tail->next) {
            tail = tail->next;
            if (tail->next) {
                tail = tail->next;
                mid = mid->next;
            }
        }
        // mid now points at middle, tail at the last
        ListNode *left = head, *right = mid->next;
        mid->next = nullptr;    // break into 2 list
        
        left = this->sortList(left);
        right = this->sortList(right);
        return this->mergeHelper(left, right);
    }
};

ListNode* Solution::mergeHelper(ListNode *left, ListNode *right){
    ListNode *hold = new ListNode(-1), *last = hold;
    while (left and right) {
        if (left->val < right->val) {
            last->next = left;
            left = left->next;
        }
        else{
            last->next = right;
            right = right->next;
        }
        last = last->next;
    }
    if (left) {
        last->next = left;
    }
    if (right) {
        last->next = right;
    }
    return hold->next;
}


vector<vector<int>> _testcases = {
    {5,},
    {4, 2, 1, 3,},
    {13, 10, 1, 11, 8,},
    {18, 16, 0, 15, 10, 7, 0},
    {},
};

ListNode* buildList(vector<int>& in);
void printNode(ListNode* head);

// ----------***************--------------------
int main(){
    Solution solve;
    for (auto vec : _testcases) {
        printNode(solve.sortList(buildList(vec)));
    }
    return 0;
}

ListNode* buildList(vector<int>& in){
    if (in.empty()) {
        return nullptr;
    }
    ListNode *head = new ListNode(in[0]), *last = head;
    for (int i = 1; i < in.size(); i++) {
        ListNode* tmp = new ListNode(in[i]);
        last->next = tmp;
        last = tmp;
    }
    return head;
}
void printNode(ListNode* head){
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }cout << "\n";
}