//
//  topcoder_jewelry.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/4/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "topcoder_jewelry.hpp"

class Solution1 {
    int answ;
    
public:
    /**
     * number of ways to assign equal value jewelries
     */
    long helper(int idx, int bob_value, int frank_value, vector<int>& jewelry){
        if (idx < 0) {
            if (bob_value == frank_value and bob_value > 0){
                return 1;
            }
            return 0;
        }
        return
            helper(idx-1, bob_value + jewelry[idx], frank_value, jewelry) +
            helper(idx-1, bob_value, frank_value + jewelry[idx], jewelry) +
            helper(idx-1, bob_value, frank_value, jewelry);
    }
    long howMany(vector<int>& jewelry){
        int idx = jewelry.size()-1;
        return helper(idx, 0, 0, jewelry);  // minus the both-nothing situation
    }
};

int main(){
    Solution1 solve;
    vector<int> inputs;
    
    inputs = {1,2,3,4,5};
    cout << solve.howMany(inputs) << "\n";
    return 0;
}