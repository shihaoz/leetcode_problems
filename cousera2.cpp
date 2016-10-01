//
//  cousera2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/26/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "cousera2.hpp"
const int _VISITED = -1;
void helper(vector<vector<int>>& matrix, int i, int j, int& count);
bool ifValid(int i, int j, vector<vector<int>>& m){
    return i >= 0 and j >= 0 and i < m.size() and j < m[0].size();
}
vector < int > countGroups(vector < vector < int > > m, vector < int > t) {
    unordered_map<int, int> _group_count;

    vector<int> answ;
    
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (m[i][j] == 1) {
                int count = 0;
                helper(m, i, j, count);
                _group_count[count]++;
            }
        }
    }
    for (int i : t) {
        answ.push_back(_group_count[i]);
    }
    return answ;
}

void helper(vector<vector<int>>& matrix, int i, int j, int& count){
    if (matrix[i][j] == 0 or matrix[i][j] == _VISITED) {
        return;
    }
    else{
        count++;
        matrix[i][j] = _VISITED;
        vector<pair<int, int>> next = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
        for (auto p : next) {
            if (ifValid(p.first, p.second, matrix)) {
                helper(matrix, p.first, p.second, count);
            }
        }
    }
}


int main(){
    
    
    return 0;
}