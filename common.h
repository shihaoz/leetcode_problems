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
#include <cassert>
#include <functional>
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
    
    const int _num_separator = 32;
    void printSeparator(char sep = '*'){
        cout << string(_num_separator, sep) << '\n';
    }
}

namespace dzTree{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        TreeNode() : TreeNode(-1){}
    };
    
    void clearMemory(TreeNode* root){
        if (root->left) {
            clearMemory(root->left);
        }
        if (root->right){
            clearMemory(root->right);
        }
        delete root;    root = nullptr;
    }
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
    void clearList(ListNode* head){
        ListNode* next;
        while(head){
            next = head->next;
            delete head;
            head = head->next;
        }
    }
}


#endif /* common_h */
