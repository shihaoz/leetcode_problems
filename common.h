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


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif /* common_h */
