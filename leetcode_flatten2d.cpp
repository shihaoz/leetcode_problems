//
//  leetcode_flatten2d.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/2/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_flatten2d.hpp"

class Vector2D {
    vector<pair<vector<int>::iterator, vector<int>::iterator>> _stream;
    int _idx;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (int i = 0; i < vec2d.size(); i++) {
            if (!vec2d[i].empty()) {
                this->_stream.emplace_back(vec2d[i].begin(), vec2d[i].end());
            }
        }
        this->_idx = 0;
    }
    
    int next() {
        int ret = *_stream[this->_idx].first++;
        if (_stream[this->_idx].first == _stream[this->_idx].second) {
            this->_idx++;
        }
        return ret;
    }
    
    bool hasNext() {
        return this->_idx < _stream.size();
    }
};

const vector<vector<vector<int>>> _testcases = {
    {
        {1,2},
        {3},
        {4,5,6},
    },
    {
        {2,1},
        {},
        {0, 5, 3},
    },
    {
        {}
    },
    {
        {3,1,2}
    },
};

int main(){
    for (auto test : _testcases) {
        Vector2D solve(test);
        while (solve.hasNext()) {
            cout << solve.next() << " ";
        }cout << "\n";
    }

    return 0;
}
