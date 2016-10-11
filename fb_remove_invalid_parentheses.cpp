//
//  fb_remove_invalid_parentheses.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fb_remove_invalid_parentheses.hpp"


class Solution {
    bool checkValid(string s);
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> answ;
        unordered_set<string> visited;  // mark string seemed
        queue<string> candidates;
        candidates.push(s); visited.insert(s);
        int size_now = candidates.size(), size_next = 0;
        while (size_now) {
            string now = candidates.front();    candidates.pop();
            if (this->checkValid(now)) {
                answ.push_back(now);
            }
            else{
                for (int i = 0; i < now.length(); i++) {
                    if ((now[i] == '(' or now[i] == ')')
                        and
                        (i == 0 or
                         (i > 0 and now[i-1] != now[i])
                         )
                        ) {
                        string tmp = now.substr(0, i) + now.substr(i+1);
                        if (visited.find(tmp) == visited.end()) {
                            candidates.push(tmp);   size_next++;
                            visited.insert(tmp);
                        }
                    }
                }
            }
            --size_now;
            if (size_now == 0 and answ.empty()) {// no answer found yet, go down a level
                swap(size_now, size_next);
            }
        }
        return answ;
    }
};
bool Solution::checkValid(string s){
    int count_left = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            count_left++;
        }
        else if(s[i] == ')'){
            count_left--;
            if (count_left < 0) {
                return false;
            }
        }
    }
    return count_left == 0;
}

const vector<string> _testcases_right = {
    "()())()",
    "(a)())()",
    ")(",
    "(((a)()",
    "(",
    "",
    "()(",
    "())(()",
};

int main(){
    Solution solve;
    
    for (string test : _testcases_right) {
        auto ret = solve.removeInvalidParentheses(test);
        dzCommon::printArray(ret, true);
    }
    return 0;
}