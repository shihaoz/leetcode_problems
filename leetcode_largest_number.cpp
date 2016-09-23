//
//  leetcode_largest_number.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/23/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_largest_number.hpp"

bool cmpLarge(string& left, string& right);

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }
        // convert all to string
        vector<string> inputs;
        for (int i : nums) {
            inputs.push_back(to_string(i));
        }
        // sort by comparator
        sort(inputs.begin(), inputs.end(), cmpLarge);

        // aggregate
        if (inputs[0][0] == '0') {
            return "0";
        }
        for (int i = 1; i < inputs.size(); i++) {
            inputs[0] += inputs[i];
        }

        return inputs[0];
    }
};

//bool cmpLarge(string& left, string& right){
//    int idx = 0, limit = min(left.size(), right.size());
//    for (; idx < limit and left[idx] == right[idx]; idx++) {
//    }
//    if (idx < limit) {
//        // within bound
//        return left[idx] > right[idx];
//    }
//    else if(left.size() == right.size()){
//        return &left < &right;    // both equal
//    }
//    else{
//        // one of them is out of bound
//        if (left.size() > right.size()) {
//            return left[idx] > right[0];
//        }
//        return !(right[idx] > left[0]);
//    }
//}
bool cmpLarge(string& left, string& right){
    return left+right > right+left;
}

const vector<vector<int>> _testcases = {
    {1240, 124},
    {128, 12},
    {82, 828},
    {53143, 5314},
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int main(){
    Solution solve;
    for (auto vec : _testcases) {
        cout << solve.largestNumber(vec) << '\n';
    }
    return 0;
}