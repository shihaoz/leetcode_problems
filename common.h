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
        for (T& i : in) {
            cout << i << " ";
        }cout << "\n";
    }
    
    const string seperator = "-------------------------\n";
}



#endif /* common_h */
