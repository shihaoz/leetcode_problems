//
//  leetcode_zigzag_iterator.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/2/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_zigzag_iterator.hpp"

class ZigzagIterator {
    vector<int>::iterator head1, head2, end1, end2;
    void swapIterator();
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        head1 = v1.begin(); end1 = v1.end();
        head2 = v2.begin(); end2 = v2.end();
        if (head1 == end1) {
            this->swapIterator();
        }
    }
    
    int next() {
        int ret = *head1++;
        this->swapIterator();
        return ret;
    }
    
    bool hasNext() {
        return !(head1 == end1 and head2 == end2);
    }
};
void ZigzagIterator::swapIterator(){
    if (head2 != end2) {
        swap(head1, head2); swap(end1, end2);
    }
}

const vector<pair<vector<int>, vector<int>>> _testcases = {
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
    },
    {
        {1},
        {4,5,6,},
    },
    {
        {1,2,3,},
        {},
    },
    {
        {},
        {4,5,4},
    }
};

int main(){
    for (auto p : _testcases) {
        ZigzagIterator solve(p.first, p.second);
        while (solve.hasNext()) {
            cout << solve.next() << " ";
        }cout << "\n";
    }
    
    return 0;
}