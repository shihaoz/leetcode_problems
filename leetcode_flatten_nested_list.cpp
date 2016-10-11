//
//  leetcode_flatten_nested_list.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/2/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_flatten_nested_list.hpp"

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int _cached_int;
    bool _cached_bool;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        _cached_bool = Iterator::hasNext();
        if (this->_cached_bool) {
            _cached_int = Iterator::next();
        }
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return this->_cached_int;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = this->_cached_int;
        _cached_bool = Iterator::hasNext();
        if (this->_cached_bool) {
            _cached_int = Iterator::next();
        }
        return ret;
    }
    
    bool hasNext() const {
        return this->_cached_bool;
    }
};
