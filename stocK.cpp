//
//  stocK.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "stocK.hpp"


class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int max_price = 0;
        
        vector<int> profits(prices.size(), 0);
        for (int i = prices.size()-1; i >= 0; i--) {
            profits[i] = max(0, max_price-prices[i]);
            max_price = max(max_price, prices[i]);
        }
        
        int max_profit = 0;
        for (int profit : profits) {
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
     
        return max_profit;
    }
    
    int maxProfit2(vector<int>& prices){
        int max_profit = 0;
        
        vector<pair<int, int>> start_end;
        int idx = 1;
        int start = 0;
        while (idx < prices.size()) {
            while (idx < prices.size() and prices[idx] >= prices[idx-1]) {
                idx++;
            }
            int end = idx-1;
            if (end > start and prices[end] > prices[start]) {
                start_end.emplace_back(start, end);
            }
            
            while (idx < prices.size() and prices[idx] < prices[idx-1]) {
                idx++;
            }
            start = idx-1;
        }
        
        
        for (auto p : start_end) {
            // calculate all the prices in between
            int start = p.first, end = p.second;
            max_profit += prices[p.second] - prices[p.first];
        }
        
        return max_profit;
    }
};


int main(){
    Solution sol;
    vector<int> inputs = {7, 1, 5, 3, 6, 4};
    
    cout << sol.maxProfit2(inputs) << "\n";
    
    inputs = {1, 2, 4, 7};
    cout << sol.maxProfit2(inputs) << "\n";
    return 0;
}