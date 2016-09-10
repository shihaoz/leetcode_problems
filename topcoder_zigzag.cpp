//
//  topcoder_zigzag.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "topcoder_zigzag.hpp"




class Solution {
    
public:
    int answ;
    
    int findSolution(vector<int>& inputs){
        vector<info> seq(inputs.size());
        
        seq[0] = info(-1, 1, TREND::none);
        
        // loop thru 1 -> (n-1)th
        for (int i = 1; i < inputs.size(); i++) {
            int here = inputs[i];
            info max_holder(-1, 1, TREND::none);
            
            for (int j = i-1; j >= 0; j--) {
                if (seq[j].last_trend == TREND::up
                    and here < inputs[j]
                    and seq[j].length+1 > max_holder.length) {
                    // this is a down sequence
                    max_holder = info(j, seq[j].length+1, TREND::down);
                }
                else if(seq[j].last_trend == TREND::down
                        and here > inputs[j]
                        and seq[j].length+1 > max_holder.length){
                    // this is a up sequence
                    max_holder = info(j, seq[j].length+1, TREND::up);
                }
                else if(seq[j].last_trend == TREND::none
                        and seq[j].length+1 > max_holder.length){
                    max_holder = info(j, seq[j].length+1,
                                      (here > inputs[j]) ? TREND::up : TREND::down);
                }
            }
            seq[i] = max_holder;
        }
        
        
        int max_so_far = -1, max_idx = -1;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i].length > max_so_far) {
                max_so_far = seq[i].length;
                max_idx = i;
            }
        }
        while (max_idx != -1) {
            cout << max_idx << "->";
            max_idx = seq[max_idx].predecessor;
        }cout << "\n";

        return max_so_far;
    }
};



int main(){
    Solution sol;
    vector<int> inputs = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
        600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
        67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
        477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
        249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };

    cout << sol.findSolution(inputs) << "\n";
    return 0;
}