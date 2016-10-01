//
//  coursera1.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/26/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "coursera1.hpp"


int findMax(vector<int>& nums){
    int result = nums[0];
    for(int i : nums){
        result = max(result, i);
    }
    return result;
}
int maxProfit(int cost_per_cut, int metal_price, vector < int > lengths) {
    if(lengths.empty()){return 0;}
    // find maximum length, and create array of all possible length
    int max_length = findMax(lengths);
    vector<int> profits(max_length+1, 0);
    for(int length = 1; length <= max_length; length++){
        // calculate profit of this length
        int pieces = 0, cuts = 0;
        for(int rod : lengths){// calculate profit from each rod
            pieces += rod/length;
            //cuts += ceil((double)rod/(double)length)-1;
            if (rod%length == 0) {
                cuts += rod/length-1;
            }
            else{
                cuts += rod/length;
            }
        }
        long profit = (long)length * pieces * metal_price;
        long cost = (long)cost_per_cut * cuts;
        if (profit > cost) {
            profits[length] = profit-cost;
        }
        else{
            profits[length] = -1;
        }
        //profits[length] = length*pieces*metal_price - cost_per_cut*cuts;
    }
    return findMax(profits);
}
int main(){
    vector<int> test1 = {26, 103, 59};
    cout << maxProfit(100, 10, test1) << '\n';
    vector<int> test2 = {26, 103, 59};
    cout << maxProfit(1, 10, test2) << '\n';
    vector<int> test3 = {1,1,1};
    cout << maxProfit(1, 2, test3) << '\n';
    return 0;
}