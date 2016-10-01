//
//  murat1.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/28/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "murat1.hpp"

using namespace dzListNode;
ListNode* optimal(ListNode* l){
    ListNode *now = l;
    unordered_set<int> _lookup;
    _lookup.insert(now->val);
    while (now->next) {
        if (_lookup.count(now->next->val) > 0) {
            ListNode *tmp = now->next;
            now->next = now->next->next;
            delete tmp;
        }
        else{
            _lookup.insert(now->next->val);
        }
        now = now->next;
    }
    
    return l;
}

int main(){
    int x = 4, *y;
    y = &x;
    (*y)++;
    cout << *y << " " << x << '\n';
    return 0;
}