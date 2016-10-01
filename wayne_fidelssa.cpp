//
//  wayne_fidelssa.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "wayne_fidelssa.hpp"


int min_flights(vector<int> arrives, vector<int> departs, int nums){
    if (nums == 0) {
        return 0;
    }
    int answ = 0, gates = 0;
    sort(departs.begin(), departs.end());
    int idx_arr = 0, idx_dep = 0;
    while (idx_arr < nums) {
        if (arrives[idx_arr] <= departs[idx_dep]) {
            gates++; idx_arr++;
            answ = max(answ, gates);
        }
        else{
            gates--; idx_dep++;
        }
    }
    return answ;
}
int pairMatch(string input){
    int last_idx = 0, answ = -1;
    stack<char> _store;
    while (last_idx < input.size()) {
        if (isupper(input[last_idx])) { // this is a upper case, store it
            _store.push(input[last_idx]);
        }
        else{// this is a lower case
            if (_store.empty()) {
                break;
            }
            char upper = _store.top();  _store.pop();
            if (upper != toupper(input[last_idx])) {    // valid
                break;
            }
            answ = last_idx;
        }
        last_idx++;
    }
    
    return answ;
}
const vector<pair<vector<int>, vector<int>>> _testcases1 = {
    {
        {900, 940, 950, 1100, 1500, 1800},
        {910, 1200, 1120, 1130, 1900, 2000},
    },
    {
        {900, 940, 950, 1100, 1500, 1800},
        {1100, 1200, 1120, 1130, 1900, 2000},
    },
    {
        {1, 2, 3, 4, 5,},
        {5, 5, 5, 5, 5,},
    }
};
const vector<string> _testcases2 = {
    "ABba",
    "PQqRrApx",
    "A",
    "a",
    "ABbCca",
    "ABbba",
};
int main(){
//    for (auto p : _testcases1) {
//        cout << min_flights(p.first, p.second, p.first.size()) << '\n';
//    }
    for (auto test : _testcases2) {
        cout << pairMatch(test) << "\n";
    }
    return 0;
}