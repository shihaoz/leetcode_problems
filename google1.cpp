//
//  google1.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "google1.hpp"

int solution(int X) {
    // write your code in C++11 (g++ 4.8.2)
    string hold = to_string(X), answ;
    bool replace = false;
    int i;
    for (i = 0; i < hold.length()-1 and !replace; i++) {
        if (hold[i+1] > hold[i]) {
            int tmp = hold[i+1] - '0' + hold[i] - '0';
            tmp += (tmp % 2 == 0) ? 0 : 1;
            answ += to_string(tmp/2);
            replace = true;
            answ += hold.substr(i+2);
        }
        else{
            answ += hold[i];
        }
    }
    if (!replace) {
        int tmp = answ.back() - '0' + hold.back() - '0';
        tmp += (tmp%2 == 0) ? 0 : 1;
        answ.back() = '0' + tmp/2;
    }
    
    return atoi(answ.c_str());
}
const vector<int> _testcases = {
    12345,
    54345,
    55,
    10000000,
    64,
    46,
    623315,
    5433221,
    998989,
};

int main(){
    for (int test : _testcases) {
        cout << solution(test) << "\n";
    }
    return 0;
}