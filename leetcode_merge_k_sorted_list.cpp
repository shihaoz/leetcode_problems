//
//  leetcode_merge_k_sorted_list.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/10/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_merge_k_sorted_list.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct node_cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {

public:
    ListNode* mergeKLists_n2(vector<ListNode*>& lists) {
        ListNode* head = nullptr, *last = new ListNode(-1);
        
        while(true){
            int min_idx = -1, min_value = numeric_limits<int>::max();
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] and lists[i]->val < min_value){
                    // update idx and value
                    min_idx = i;    min_value = lists[i]->val;
                }
            }
            if (min_idx == -1){
                return head;
            }
            if (!head){
                head = lists[min_idx];
            }
            // update last
            last->next = lists[min_idx];
            last = last->next;
            // increment lists ptr
            lists[min_idx] = lists[min_idx]->next;
        }

        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists);
    ListNode* merge2List(ListNode* one, ListNode* two);
    ListNode* mergeKLists_nlogn(vector<ListNode*>& lists);
};
ListNode* Solution::mergeKLists_nlogn(vector<ListNode*>& lists){
    if(lists.empty()){return nullptr;}
    
    int low = 0, high = lists.size()-1;
    while(low < high){
        int mid = low + (high-low)/2;
        while(low < high){
            lists[low] = this->merge2List(lists[low], lists[high]);
            low++;  high--;
        }
        low = 0;
        high = mid;
    }
    return lists[0];
}
ListNode* Solution::merge2List(ListNode* one, ListNode* two){
    ListNode* head, *last;
    if(!one){return two;}
    if(!two){return one;}
    if(one->val < two->val){
        head = last = one;
        one = one->next;
    }
    else{
        head = last = two;
        two = two->next;
    }
    while(one and two){
        if (one->val < two->val){
            last->next = one;   one = one->next;
        }
        else{
            last->next = two;   two = two->next;
        }
        last = last->next;
    }
    if (one){
        last->next = one;
    }
    if (two){
        last->next = two;
    }
    return head;
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists){
    ListNode* head = nullptr, *last = nullptr;
    priority_queue<ListNode*, vector<ListNode*>, node_cmp> heap;
    
    for (int i = 0; i < lists.size(); i++){
        if (lists[i]){
            heap.push(lists[i]);
        }
    }
    if(heap.empty()){
        return nullptr;
    }
    
    head = last = heap.top();
    heap.pop(); // pop the first one, since it is recorded
    if(head->next){
        heap.push(head->next);
    }
    while(!heap.empty()){
        ListNode* now = heap.top(); heap.pop();
        last->next = now;
        if(now->next){
            heap.push(now->next);
        }
        last = last->next;
    }
    return head;
}


const vector<vector<vector<int>>> _testcases = {
    {
        {1, 3, 5, 9},
        {2, 10, 12},
        {0,},
        {7, 8},
    },
    {
        {1,},
        {2,},
        {3,},
    },
    {
        {5,8,9,10},
        {1},
        {15, 16, 20},
    },
    {
        {},
        {}
    },
    {
        {},
        {1},
    },
    {
        {1, 2, 2},
        {1, 1, 2},
    },
};
void printArray(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }cout << '\n';
}
int main(){
    Solution solve;
    for (auto matrix : _testcases){
        vector<ListNode*> inputs;
        for (auto& vec : matrix){
            if(vec.empty()){
                inputs.push_back(nullptr);
            }
            else{
                ListNode* head = new ListNode(vec[0]);
                inputs.push_back(head);
                for(int i = 1; i < vec.size(); i++){
                    head->next = new ListNode(vec[i]);
                    head = head->next;
                }
            }
        }
        
        printArray(solve.mergeKLists_nlogn(inputs));
    }
    return 0;
}