//
//  topcoder_flower_garden.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/28/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "topcoder_flower_garden.hpp"

/**

 
 You are planting a flower garden with bulbs to give you joyous flowers throughout the year. However, you wish to plant the flowers such that they do not block other flowers while they are visible.
 
 You will be given a int[] height, a int[] bloom, and a int[] wilt. Each type of flower is represented by the element at the same index of height, bloom, and wilt.
    height represents how high each type of flower grows, bloom represents the morning that each type of flower springs from the ground, and wilt represents the evening that each type of flower shrivels up and dies. 
 Each element in bloom and wilt will be a number between 1 and 365 inclusive, and wilt[i] will always be greater than bloom[i]. 
 >> You must plant all of the flowers of the same type in a single row for appearance, 
 >> and you also want to have the tallest flowers as far forward as possible. 
 >> However, if a flower type is taller than another type, and both types can be out of the ground at the same time, the shorter flower must be planted in front of the taller flower to prevent blocking. A flower blooms in the morning, and wilts in the evening, so even if one flower is blooming on the same day another flower is wilting, one can block the other.
 
 You should return a int[] which contains the elements of height in the order you should plant your flowers to acheive the above goals. The front of the garden is represented by the first element in your return value, and is where you view the garden from. The elements of height will all be unique, so there will always be a well-defined ordering.
 

*/
#define bck_ptr unique_ptr<Bucket>
struct iii {
    int height;
    int bloom;
    int wilt;
    iii(int h, int b, int w): height(h), bloom(b), wilt(w){
        
    }
};

struct ii{
    int height;
    int wilt;
    ii(int h, int w): height(h), wilt(w){
    }
};

bool iiiCmp(iii& left, iii& right){
    return (left.bloom != right.bloom) ? left.bloom < right.bloom : left.wilt < right.wilt;
}

class Bucket{
private:
    int _max;
    
public:
    int left, right;
    vector<bool> heights;
    
    Bucket (int l, int r) : left(l), right(r) {
        this->_max = -1;
        this->heights = vector<bool>(1001, false);
    }
    Bucket(){
        // default constructor
    }
    void store(int in){
        this->heights[in] = true;
        this->_max = max(in, this->_max);
    }
    void extendRight(int right){
        this->right = max(right, this->right);
    }
    
    void print(){
        for (int i = 0; i < this->heights.size(); i++) {
            if (this->heights[i]) {
                cout << i << " ";
            }
        }
    }
    int getMax() const { return this->_max;}
};

bool bucketCmp(Bucket& left, Bucket& right){
    return left.getMax() > right.getMax();
}
unique_ptr<Bucket> createBucket(int left, int right){
    return unique_ptr<Bucket>(new Bucket(left, right));
}

class Solution {
    const int _num_bloom = 366;
    const int _num_height = 1001;
public:
    void flowerGarden_n(vector<int>& heights, vector<int>& bloom, vector<int>& wilt){
        /**
         * ii: height, wilt
         * inputs: <bloom, ii[]>
         * groups: <max height, *Bucket>
         */
        vector<vector<ii>> inputs(this->_num_bloom);
        for (int i = 0; i < heights.size(); i++) {
            inputs[bloom[i]].emplace_back(heights[i], wilt[i]);
        }
        
        vector<bck_ptr> groups(this->_num_height);

        // find first element
        int idx = 0;
        while (idx < inputs.size() and inputs[idx].empty()) {
            idx++;
        }
        bck_ptr now = createBucket(idx, inputs[idx][0].wilt);
        
        for (idx; idx < inputs.size(); idx++) {
            
            if (!inputs[idx].empty()) {
                // not empty
                
                if (idx <= now->right) {
                    // include all into this bucket
                    for (ii& ele : inputs[idx]) {
                        now->store(ele.height);
                        now->extendRight(ele.wilt);
                    }
                }
                else{
                    // a new bucket is needed
                    int tmp = now->getMax();
                    groups[tmp] = move(now);
                    now = createBucket(idx, inputs[idx][0].wilt);
                    idx--;  // loop over same bloom again
                }
            }
        }// end: for
        int tmp = now->getMax();
        groups[tmp] = move(now);
        for (int i = groups.size()-1; i >= 0; i--) {
            if (groups[i]) {
                groups[i]->print();
            }
        }cout << "\n";
    }
    
    void flowerGarden_nlogn(vector<int>& heights, vector<int>& bloom, vector<int>& wilt){
        
        
        
        vector<iii> inputs;
        vector<Bucket> answs;
        for (int i = 0; i < heights.size(); i++) {
            inputs.emplace_back(heights[i], bloom[i], wilt[i]);
        }
        sort(inputs.begin(), inputs.end(), iiiCmp);
        
        
        Bucket now(inputs[0].bloom, inputs[0].wilt);  now.store(inputs[0].height);
        
        int idx = 0;
        while (++idx < heights.size()) {
            if (inputs[idx].bloom <= now.right) {
                now.extendRight(inputs[idx].wilt);
            }
            else{ // create a new bucket
                answs.push_back(now);
                now = Bucket(inputs[idx].bloom, inputs[idx].wilt);
            }
            now.store(inputs[idx].height);
        }
        answs.push_back(now);
        
        sort(answs.begin(), answs.end(), bucketCmp);
        for (auto & ele : answs) {
            ele.print();
        }cout << "\n";
    }


};

int main(){
    Solution solve;
    vector<int> input1, input2, input3;
    
    
    input1 = {3,2,5,4},
    input2 = {1,2,11,10},
    input3 = {4,3,12,13};
    solve.flowerGarden_n(input1, input2, input3);
    
    
    input1 = {1,2,3,4,5,6},
    input2 = {1,3,1,3,1,3},
    input3 = {2,4,2,4,2,4};
    solve.flowerGarden_n(input1, input2, input3);
    
    
    input1 = {5,4,3,2,1},
    input2 = {1,5,10,15,20},
    input3 = {5,10,14,20,25};
    solve.flowerGarden_n(input1, input2, input3);
    
    input1 = {5,4,3,2,1},
    input2 = {1,5,10,15,20},
    input3 = {5,10,15,20,25};
    solve.flowerGarden_n(input1, input2, input3);
    
    input1 = {5,4,3,2,1},
    input2 = {1,5,10,15,20},
    input3 = {4,9,14,19,24};
    solve.flowerGarden_n(input1, input2, input3);
    
    
    input1 = {5,4,3,2,1},
    input2 = {1,1,1,1,1},
    input3 = {365,365,365,365,365};
    solve.flowerGarden_n(input1, input2, input3);
    return 0;
}
