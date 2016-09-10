//
//  leetcode_missing_ranges.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/31/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_missing_ranges.hpp"

void print(vector<string> in){
    for (string str : in) {
        cout << str << " ";
    }cout << "\n";
}

struct TestSuite {
    int lower, upper;
    vector<int> inputs;
};
const vector<TestSuite> _TESTS = {
    {1, 5, {1,2,3,4,5} },   // test all inputs
    {1, 1, {1} },           // test upper=lower
    {1, 1, {} },           // test upper=lower
    {1, 99, {1, 99} },      // random test
};
class Solution {
    vector<string> answ;
    
    void _addPair(pair<int, int> p){
        if (p.first < p.second) {
            answ.push_back(to_string(p.first) + "->" + to_string(p.second));
        }
        else{
            answ.push_back(to_string(p.first));
        }
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        answ.clear();
        if (nums.size() == upper-lower+1) {
            return {};
        }
        
        int ele = lower;
        vector<int>::iterator it = nums.begin();
        while (ele <= upper and it != nums.end()) {
            if (*it == ele) {
                /// match
            }
            else{
                /// no match
                this->_addPair(make_pair(ele, *it-1));
                ele = *it;
            }
            it++;   ele++;
        }
        
        if (ele <= upper) {
            this->_addPair(make_pair(ele, upper));
        }
        return answ;
    }
};

int main(){
    Solution solve;
    vector<int> inputs;
    
    inputs = {0, 1, 3, 50, 75};
    print(solve.findMissingRanges(inputs, 0, 99));
    
    for (auto t : _TESTS) {
        print(solve.findMissingRanges(t.inputs, t.lower, t.upper));
    }
    return 0;
}