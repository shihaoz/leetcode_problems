//
//  test_lambda.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/9/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "test_lambda.hpp"

void applyForEach(function<void (int)> func){
    vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
    for_each(numbers.begin(), numbers.end(), func);
}
int main(){
    int a = 1, b = 7;
    
    auto test1 = [&a, &b](){
        a = a*b;
        b = b*a;
    };
    test1();
    cout << a << " " << b << "\n";
    
    auto test2 = [](int x, int y) -> int { return x + y; };
    cout << test2(5, 7) << '\n';
    
    vector<int> test3 = { 1, 2, 3, 4, 5, 6, 7, 8};
    int count5 = count_if(test3.begin(), test3.end(), [](int x){return x > 5;});
    cout << count5 << "\n";
    
    int sum = 0;
    int divisor = 3;
    vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
    for_each(numbers.begin(), numbers.end(), [divisor, &sum] (int y)
             {
                 if (y % divisor == 0)
                 {
                     cout << y << ' ';
                     sum += y;
                 }
             });cout << '\n';
    
    cout << sum << '\n';
    
    auto printer = [](int x){ cout << x << ' ';};
    applyForEach(printer);  cout << '\n';
    return 0;
}