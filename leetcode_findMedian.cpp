//
//  leetcode_findMedian.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/2/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_findMedian.hpp"

class MedianFinder {
    priority_queue<double, vector<double>, less<double>> lowerHeap;     // maxHeap
    priority_queue<double, vector<double>, greater<double>> higherHeap; // minHeap
public:
    // Adds a number into the data structure.
    void addNum(int num) {  // maintain the balance
        if (!higherHeap.empty() and num > higherHeap.top()) {
            higherHeap.push(num);
        }
        else{
            lowerHeap.push(num);
        }
        while ((int)lowerHeap.size() - (int)higherHeap.size() > 1) {
            higherHeap.push(lowerHeap.top());   lowerHeap.pop();
        }
        while ((int)higherHeap.size() - (int)lowerHeap.size() > 1) {
            lowerHeap.push(higherHeap.top());   higherHeap.pop();
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {

        if (lowerHeap.size() == higherHeap.size()) {
            return (lowerHeap.top() + higherHeap.top())/2;
        }
        return (lowerHeap.size() > higherHeap.size()) ? lowerHeap.top() : higherHeap.top();
    }
};
const vector<vector<int>> _testcases = {
    {1,2,3,4,5,6,7,},
    {1, 8, 5, 9, 7, 2, 2,},
};
int main(){
    for (auto test : _testcases) {
        MedianFinder solve;
        for (int i : test) {
            solve.addNum(i);
            cout << solve.findMedian() << " "; flush(cout);
        }cout << "\n";
    }
    return 0;
}