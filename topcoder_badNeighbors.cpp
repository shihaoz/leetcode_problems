//
//  topcoder_badNeighbors.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/27/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "topcoder_badNeighbors.hpp"


class Solution {
    
private:

public:
    int badNeighbors(vector<int>& donations){
        if (donations.size() < 3) {
            return (donations.empty()) ? 0 : *max_element(donations.begin(), donations.end());
        }
        
        vector<int> max_totals(donations.size(), 0), max_totals2(donations.size(), 0);
        max_totals[0] = donations[0];
        max_totals[1] = max_totals2[1] = donations[1];
        
        int S1max = max_totals[0],
        S2max = 0;
        
        for (int idx = 2; idx < donations.size(); idx++) {
            
            // find max element
            max_totals[idx] = S1max + donations[idx];
            
            // find max element without the first one (for the last element)
            max_totals2[idx] = S2max + donations[idx];
            
            S1max = max(S1max, max_totals[idx-1]);
            S2max = max(S2max, max_totals2[idx-1]);
        }
        max_totals.back() = max_totals2.back();
        return *max_element(max_totals.begin(), max_totals.end());
    }
    int badNeighbors2(vector<int>& donations){
        if (donations.size() <= 1) {
            return (donations.empty()) ? 0 : *donations.begin();
        }
        
        vector<int> max_totals(donations.size(), 0),
                max_totals2(donations.size(), 0);
        max_totals[0] = donations[0];
        max_totals[1] = max_totals2[1] = donations[1];
        
        
        for (int idx = 2; idx < donations.size()-1; idx++) {

            // find max element
            auto it = max_element(max_totals.begin(), max_totals.begin() + idx - 1);
            max_totals[idx] = *it + donations[idx];
                
            // find max element without the first one (for the last element)
            int tmp = (idx-2 > 0) ?
                          *max_element(max_totals2.begin()+1, max_totals2.begin() + idx - 1)
                           : 0; // if ptr == 0, then no previous element is available.
                                // Can't choose n-1, n-2 is first element.
            max_totals2[idx] = tmp + donations[idx];
        
        }
        /// if donation size == 2, the last element is already computed.
        int idx = donations.size()-1;
        if (idx > 1) {
            // for the last element,
            // max = maximum of elements between [2nd, last 3nd] that don't use first one + itself.
            max_totals.back() = *max_element(max_totals2.begin()+1, max_totals2.begin()+idx-1) + donations.back();
        }
        
        
        return *max_element(max_totals.begin(), max_totals.end());
    }
};


int main(){
    Solution solve;
    vector<int> inputs;
    
    inputs = { 10, 3, 2, 5, 7, 8 };
    cout << solve.badNeighbors(inputs) << "\n";
    
    inputs = {11, 15};
    cout << solve.badNeighbors(inputs) << "\n";

    inputs = {7, 7, 7, 7, 7, 7, 7};
    cout << solve.badNeighbors(inputs) << "\n";
    
    inputs = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    cout << solve.badNeighbors(inputs) << "\n";

    inputs = {3, 2, 0, 4, 0, 5};
    cout << solve.badNeighbors(inputs) << "\n";
    
    inputs = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
        6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
        52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
    cout << solve.badNeighbors(inputs) << "\n";

    return 0;
}



