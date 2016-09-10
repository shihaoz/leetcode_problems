//
//  leetcode_longest_absolute_filepath.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/31/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_longest_absolute_filepath.hpp"

struct inode {
    string name;
    shared_ptr<inode> parent;
    int length;
    inode(string n): name(n){
        parent = nullptr;
        length = 0;
    }
};
const string sample1 = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
const string sample2 = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
const string sample3 = sample1 + "\n\tsublongestdirectory"; // test folder doesn't count
const string sample4 = sample2 + "\nabbsabdsabdbasbdbasbdabbbsadbabsdbabsbdabsdbasbdabsbbasda.csv"; // test up several directory
/**
e.g: dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext
e.g: dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext
 */
void printPair(pair<string, int> in){
    cout << in.first << ", " << in.second << "\n";
}
class Solution {

    int _answ = 0;
    int _parser = 0;
    string _input;

    bool _isFile(shared_ptr<inode> ptr){
        return ptr->name.find('.') != string::npos;
    }
public:
    string _getLine(){
        if (this->_parser == string::npos) {
            return string();
        }
        int idx = this->_parser;
        this->_parser = this->_input.find('\n', this->_parser);
        if (this->_parser == string::npos) {
            return this->_input.substr(idx);
        }
        string ret = this->_input.substr(idx, this->_parser-idx);
        this->_parser++;
        return ret;
    }
    pair<string, int> _getNext(){
        string tmp = _getLine(), name; int level = 0;
        
        int idx = 0;
        while (tmp.find("\t", idx) != string::npos) {
            level++;    idx += 1;
        }
        name = tmp.substr(idx);
        return make_pair(name, level);
    }
    void _initParser(string in){
        this->_parser = 0;
        this->_input = in;
    }
    int lengthLongestPath(string input) {
        shared_ptr<inode> last_node(new inode(""));
        last_node->length = -1;  // imaginary root node
        int level_now = -1, level_next = -1;
        
        this->_initParser(input);
        pair<string, int> info = this->_getNext();

        while (!info.first.empty()) {
            shared_ptr<inode> new_node(new inode(info.first));
            level_next = info.second;
            
            if (level_next > level_now) {
            }
            else if(level_next == level_now){
                last_node = last_node->parent;
            }
            else{/// level_next < level_now, can go up multiple level
                
                last_node = last_node->parent;  // same level will perform once
                int level_diff = level_now - level_next;
                while (level_diff--) {
                    last_node = last_node->parent;
                }
            }
            // set parent
            new_node->parent = last_node;
            
            // set length
            new_node->length = new_node->parent->length + 1 + new_node->name.length();

            // update length
            if (this->_isFile(new_node)) {
                this->_answ = max(this->_answ, new_node->length);
            }
            
            // update last_node
            last_node = new_node;
            
            // update level
            level_now = level_next;
            
            info = this->_getNext();
        }
        return this->_answ;
    }
};

int main(){
    Solution solve;
    solve._initParser(sample2);
    string a = solve._getLine();
    while (!a.empty()) {
        cout << a << '\n';
        a = solve._getLine();
    }
    cout << solve.lengthLongestPath(sample1) << "\n";
    cout << solve.lengthLongestPath(sample2) << "\n";
    cout << solve.lengthLongestPath(sample3) << "\n";
    cout << solve.lengthLongestPath(sample4) << "\n";
    
    
    return 0;
}