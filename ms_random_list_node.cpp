//
//  ms_random_list_node.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/26/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "ms_random_list_node.hpp"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> _lookup;
        _lookup[nullptr] = nullptr;
        RandomListNode *dummy = new RandomListNode(-1), *last = dummy;
        // build the new list
        for (RandomListNode* oldNode = head; oldNode != nullptr; oldNode = oldNode->next) {
            RandomListNode *newNode = new RandomListNode(oldNode->label);
            last->next = newNode;   // connect ->next
            _lookup[oldNode] = newNode;
            last = newNode;
        }
        last = dummy->next;
        for (RandomListNode *oldNode = head; oldNode != nullptr;
                oldNode = oldNode->next, last = last->next) {
            last->random = _lookup[oldNode->random];
        }
        return dummy->next;
    }
};

const vector<vector<int>> _testcases = {
    {1,2,3,4,5,}
};

int main(){
    Solution solve;
    
    auto test = _testcases[0];
    vector<RandomListNode*> _storage;
    RandomListNode *head = new RandomListNode(test[0]), *last = head;
    _storage.push_back(head);
    for (int i = 1; i < test.size(); i++) {
        head->random = last;
        last->next = new RandomListNode(test[i]);
        last = last->next;
        _storage.push_back(last);
    }
    _storage[0]->random = _storage[4];
    _storage[1]->random = _storage[3];
    _storage[2]->random = nullptr;
    _storage[3]->random = _storage[2];
    _storage[4]->random = _storage[1];
    RandomListNode *newHead = solve.copyRandomList(head);
    
    for (; newHead != nullptr; newHead = newHead->next) {
        cout << "label: " << newHead->label << " next-label: ";
        if (newHead->next) {
            cout << newHead->next->label;
        }
        else{
            cout << "XX";
        }
        cout << " random-label: ";
        if (newHead->random) {
            cout << newHead->random->label;
        }
        else{
            cout << "XX";
        }
        cout << endl;
    }
    
    _storage.clear();
    head = new RandomListNode(10);  head->next = head->random = nullptr;
    newHead = solve.copyRandomList(head);
    cout << "label: " << newHead->label << " next-label: ";
    if (newHead->next) {
        cout << newHead->next->label;
    }
    else{
        cout << "XX";
    }
    cout << " random-label: ";
    if (newHead->random) {
        cout << newHead->random->label;
    }
    else{
        cout << "XX";
    }
    cout << endl;
    return 0;
}