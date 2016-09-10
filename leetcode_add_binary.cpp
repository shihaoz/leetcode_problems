#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    int _toInt(char c){
        return c - '0';
    }
public:
    string addBinary2(string a, string b) {
        
        string::reverse_iterator it_a = a.rbegin(), it_b = b.rbegin();
        string result;  result.reserve(max(a.size(), b.size()));
        int carry_bit = 0; // the carry bit

        while(it_a != a.rend() and it_b != b.rend()){
            int sum = _toInt(*it_a) + _toInt(*it_b) + carry_bit;
            carry_bit = sum/2;
            result = to_string(sum%2) + result;
            it_a++; it_b++;
        }
        
        auto it_final = (it_a == a.rend()) ? it_b : it_a;
        auto it_end = (it_a == a.rend()) ? b.rend() : a.rend();
        
        if(carry_bit == 1){
            while(it_final != it_end and *it_final == '1'){
                result = '0' + result;
                it_final++;
            }
            result = '1' + result;
            
            if(it_final == it_end){  // stop if end is reached
                return result;
            }
            it_final++;  // increment past the '1'
        }
        
        while(it_final != it_end){
            result = *it_final + result;
            it_final++;
        }
        return result;
    }
    
    string addBinary(string a, string b){
        string answ;
        int i = a.size()-1, j = b.size()-1, carry = 0;
        while (i >= 0 or j >= 0 or carry > 0) {
            carry += (i >= 0) ? _toInt(a[i--]) : 0;
            carry += (j >= 0) ? _toInt(b[j--]) : 0;
            answ = to_string(carry%2) + answ;
            carry = (carry >= 2);
        }
        return answ;
    }
};
const vector<pair<string, string>> _testcases = {
    make_pair("11", "1"),       // 100
    make_pair("10011", "1"),    // 10100
    make_pair("111", "111"),    //  1110
    make_pair("", "100"),       // 100
    make_pair("1", "1"),        // 10
    make_pair("100000", "11111"), // 111111
    make_pair("000", "101"),    // 101,
    make_pair("", ""),          // nothing
};
int main(){
    Solution solve;
    for (auto p : _testcases) {
        cout << solve.addBinary(p.first, p.second) << "\n";
    }
    return 0;
}
