//
//  topcoder_zigzag.hpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/25/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef topcoder_zigzag_hpp
#define topcoder_zigzag_hpp

#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum TREND{
    up = 1,
    down = -1,
    none = 0
};
struct info {
    int predecessor;
    int length;
    TREND last_trend;
    info(int p, int l, TREND t): predecessor(p), length(l), last_trend(t){
        
    }
    info(){
        predecessor = length = -1;
        last_trend = TREND::none;
    }
};

#endif /* topcoder_zigzag_hpp */
