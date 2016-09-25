//
//  common.h
//  leetcode2016
//
//  Created by Shihao Zhang on 9/7/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef common_h
#define common_h
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <list>
#include <cassert>
#include <sstream>
#include <stack>
#include <numeric>
using namespace std;
namespace dzCommon {
    template <class T>
    void printArray(vector<T> in, bool size = false) {
        if (size){
            cout << "size: " << in.size() << "\n";
        }
        cout << "[";
        for (T& i : in) {
            cout << i << " ";
        }cout << "]\n";
    }
    
    template <class T>
    void printArrayArray(vector<vector<T>> in, bool size = false) {
        if(size){
            cout << "size: " << in.size() << "\n";
        }
        for (auto& vec : in) {
            printArray(vec);
        }
    }
    
    const string seperator = "-------------------------\n";
}
namespace dzInterval{
    struct Interval{
        int start, end;
        Interval(): start(0), end(0){};
        Interval(int s, int e): start(s), end(e){};
    };
    void printIntervalArray(vector<Interval> inputs){
        for (Interval i : inputs){
            cout << "(" << i.start << ", " << i.end << ") ";
        }cout << "\n";
    }
}
namespace dzListNode {
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* buildList(vector<int>& vec){
        if (vec.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(vec[0]), *last = head;
        for (int i = 1 ; i < vec.size(); i++) {
            last->next = new ListNode(vec[i]);
            last = last->next;
        }
        return head;
    }
    void printList(ListNode* head){
        while(head){
            cout << head->val << " ";
            head = head->next;
        }cout << "\n";
    }
}


#endif /* common_h */
