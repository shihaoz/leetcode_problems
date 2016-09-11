//
//  leetcode_tree_serialize.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 9/10/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_tree_serialize.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    void _serialize_helper(string& answ, TreeNode* root);
    TreeNode* _deserialize_helper(string& answ, int& idx);
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string answ;
        this->_serialize_helper(answ, root);
        return answ;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* head; int idx = 0;
        head = this->_deserialize_helper(data, idx);
        return head;
    }
};
void Codec::_serialize_helper(string &answ, TreeNode *root){
    if (!root) {
        answ += ",";
    }
    else{
        answ += to_string(root->val) + ",";
        this->_serialize_helper(answ, root->left);
        this->_serialize_helper(answ, root->right);
    }
}
TreeNode* Codec::_deserialize_helper(string &answ, int &idx){
    if (idx >= answ.size()) {
        return nullptr;
    }
    // get this value
    int end = answ.find(',', idx);
    string value = answ.substr(idx, end-idx).c_str();
    idx = end+1;
    if (value.empty()) {
        return nullptr;
    }
    else{
        TreeNode* root = new TreeNode(atoi(value.c_str()));
        root->left = this->_deserialize_helper(answ, idx);
        root->right = this->_deserialize_helper(answ, idx);
        return root;
    }
}
const vector<string> _testcases = {
    "1,2,,,3,4,,,5,,6,,,",
    "1,,2,,3,,4,,5,,,",
    ",",
    "1,,,",
    "1,2,,,3,,,",
};
int main(){
    Codec solve; cout << boolalpha;
    for (string str : _testcases) {
        TreeNode* hold = solve.deserialize(str);
        string ret = solve.serialize(hold);
        cout << (str == ret) << '\n';
    }
    return 0;
}
