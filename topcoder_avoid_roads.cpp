//
//  topcoder_avoid_roads.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/30/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "topcoder_avoid_roads.hpp"

struct CROSS {
    bool goUp, goRight;
    long ways;  // number of ways to get here
    CROSS(): goUp(true), goRight(true){
        ways = 0;
    }
};
class Solution {
    int _x, _y;
    vector<vector<CROSS>> _roads;
    
    bool checkValid(int x, int y){
        return x >= 0 and y >= 0 and
            x <= this->_x and y <= this->_y;
    }
    bool checkUp(int x, int y){
        return checkValid(x+1, y) and this->_roads[x][y].goUp;
    }
    bool checkRight(int x, int y){
        return checkValid(x, y+1) and this->_roads[x][y].goRight;
    }
    
    vector<int> split(string& input, char sep){
        int start = 0, end = input.find(sep);
        vector<int> ret;
        while (end != string::npos) {
            ret.push_back(atoi(input.substr(start, end+1).c_str()));
            start = end+1;
            end = input.find(sep, start);
        }
        ret.push_back(atoi(input.substr(start).c_str()));
        
        if (ret[0] > ret[2] or ret[1] > ret[3]) {
            swap(ret[0], ret[2]);
            swap(ret[1], ret[3]);
        }
        return ret;
    }
    
public:
    long avoidRoad(int width, int height, vector<string> badRoads){
        this->_x = height;  this->_y = width;
        // fill _badRoads
        _roads = vector<vector<CROSS>>(height+1, vector<CROSS>(width+1));
        _roads[0][0].ways = 1;
        
        for (auto str : badRoads) {
            vector<int> hold = this->split(str, ' ');
            int y1 = hold[0], x1 = hold[1], y2 = hold[2], x2 = hold[3];
            if (x2 > x1) {
                this->_roads[x1][y1].goUp = false;
            }
            else{
                this->_roads[x1][y1].goRight = false;
            }
        }
        
        for (int i = 0; i < this->_roads.size(); i++) {
            for (int j = 0; j < this->_roads[i].size(); j++) {
                if (checkUp(i, j)) {
                    this->_roads[i+1][j].ways += this->_roads[i][j].ways;
                }
                if (checkRight(i, j)) {
                    this->_roads[i][j+1].ways += this->_roads[i][j].ways;
                }
            }
        }
        return this->_roads[height][width].ways;
    }
    
};


int main(){
    /**
     6
     6
     {"0 0 0 1","6 6 5 6"}
     */
    Solution avoidRoads;
    
    cout << avoidRoads.avoidRoad(6, 6, {"0 0 0 1","6 6 5 6"}) << "\n";
    cout << avoidRoads.avoidRoad(1, 1, {}) << "\n";
    cout << avoidRoads.avoidRoad(2, 2, {"0 0 1 0", "1 2 2 2", "1 1 2 1"}) << "\n";
    cout << avoidRoads.avoidRoad(35, 31, {}) << "\n";
    cout << avoidRoads.avoidRoad(2, 2, {"1 2 2 2", "1 1 2 1", "1 2 1 1"}) << "\n";
    return 0;
}
