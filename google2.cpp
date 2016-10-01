//
//  google2.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "google2.hpp"

void pop_last(string& str){
    str.erase(str.find_last_of('/'));
}
int count_zeros(string& str){
    int count = 0;
    for (int i = 0; i < str.size() and str[i] == ' '; i++) {
        count++;
    }
    str = str.substr(count);
    return count;
}
vector<string> _valid_file_names = {".jpeg", ".png", ".gif"};
int solution(string &S) {
    stringstream ss;
    ss << S;
    int level = -1, max_length = 0;
    string dir_path, holder;
    
    while (getline(ss, holder)) {
        int level_diff = level -  count_zeros(holder);
        while (level_diff >= 0 and !dir_path.empty()) {
            pop_last(dir_path);
            level_diff--;
            level--;
        }
        // at the correct level,
        // check file name
        if (holder.find('.') != string::npos) {// this is a file
            bool is_image = false;
            for (int i = 0; i < _valid_file_names.size() and !is_image; i++) {
                is_image = (holder.find(_valid_file_names[i]) != string::npos);
            }
            if (is_image) {
                max_length = max(max_length, (int)dir_path.length());
            }
        }
        else{   // this is a folder
            dir_path += '/' + holder;
            level += 1;
        }
    }
    return max_length;
}

const vector<string> _testcases = {
"dir1\n\
 dirl1\n\
 dirl2\n\
  picture.jpeg\n\
  dirl21\n\
  file1.txt\n\
dir2\n\
 file2.gif",
    "dir1\n dirl1\n  picture.gif\n  dirl2\n   abc.gif\n",
    "dir1\n dirl1\n  picture.gif\n  dirl2\n   abc.gif\naaabababababababab\n a.jpeg", //19
    "",
    "abcdefg\nabcdfef\nsad\n",
    "dir1\n dir11\n dir12\n  picture.jpeg\n  dir121\n   a.gif\n  file1.txt\ndir2\n file2.gif",
};

int main(){
    
    for (string str : _testcases) {
        cout << solution(str) << '\n';
    }
    return 0;
}
