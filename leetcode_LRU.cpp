//
//  leetcode_LRU.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 8/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "leetcode_LRU.hpp"

class LRUlist{
    list<pair<int, int>> _list;
    
public:
    list<pair<int, int>>::iterator push(int key, int value){
        _list.emplace_back(key, value);
        return --_list.end();
    }
    int getSize() const {
        return this->_list.size();
    }
    int popLRU(){
        // only trigger when capacity is reached
        if (this->_list.empty()) {
            return -1;
        }
        int key = this->_list.front().first;
        this->_list.pop_front();
        return key;
    }
    
    list<pair<int, int>>::iterator update(list<pair<int, int>>::iterator& it, int value){
        list<pair<int, int>>::iterator ret = this->update(it);
        ret->second = value;
        return ret;
    }
    list<pair<int, int>>::iterator update(list<pair<int, int>>::iterator& it){
        pair<int, int> hold = *it;
        this->_list.erase(it);
        return this->push(hold.first, hold.second);
    }
    
    void printLRU(){
        auto it = this->_list.begin();
        while (it != this->_list.end()) {
            cout << it++->second << "";
        }cout << "\n";
    }
};
class LRUCache{
    unordered_map<int, list<pair<int, int>>::iterator> _container;
    LRUlist _lru;
    int _capacity;

public:
    LRUCache(int capacity) {
        this->_capacity = capacity;
    }
    
    int get(int key) {
        // if not-in _container, return -1
        if (_container.find(key) == _container.end()) {
            return -1;
        }
        // else:
        /**
         1. get iterator, update the iterator
         2. return the value
         */
        else{
            auto it = this->_container[key];
            it = this->_lru.update(it);
            this->_container[key] = it;

            // comment out this line
            this->_lru.printLRU();
            return it->second;
        }
    }
    
    void set(int key, int value) {

        /**
         if in: update lru
         */
        if (this->_container.find(key) != this->_container.end()) {
            this->_container[key] = this->_lru.update(this->_container[key], value);
        }
        /**
         if not-in:
         if full, kick out head
         
         1. push to lru
         2. store in container
         */
        else{
            if (this->_lru.getSize() == this->_capacity) {
                int pop_key = this->_lru.popLRU();
                this->_container.erase(pop_key);
            }
            auto it = this->_lru.push(key, value);
            this->_container[key] = it;
        }
        
        // comment out this line
        this->_lru.printLRU();
    }
};
#define cellptr unique_ptr<LRUcell>
#define linkmap unordered_map<int, cellptr>

struct LRUcell {
    int value;
    linkmap::iterator parent, child;
    LRUcell(int v): value(v){
        // constructor
    }
};

class LRUcache2 {
    linkmap::iterator _head, _tail, _NOT_FOUND;
    linkmap _container;

    int _count;
    int _capacity;
    
    void _updateIterator(linkmap::iterator& it){
        // update an iterator
        // connect parent and child
        auto parent = it->second->parent, child = it->second->child;
        if (parent != this->_NOT_FOUND) {
            parent->second->child = child;
        }
        if (child != this->_NOT_FOUND) {
            child->second->parent = parent;
        }
        this->_count--;
        this->_pushIterator(it);
    }
    void _pushIterator(linkmap::iterator& it){
        // check tail
        it->second->parent = this->_tail;
        it->second->child = this->_NOT_FOUND;
        this->_tail = it;
        if (this->_count == 0) {
            this->_head = it;
        }
        this->_count++;
    }
    void _popIterator(){
        linkmap::iterator it = this->_head;
        if (this->_count > 1) {
            // set child's parent to null
            // set head to child
            auto& child_it = it->second->child;
            child_it->second->parent = this->_NOT_FOUND;
            this->_head = child_it;
        }
        else{
            // set head, tail to null
            this->_head = this->_tail = this->_NOT_FOUND;
        }
        this->_count--;
        this->_container.erase(it);
    }
public:
    /**
     constructor
     */
    LRUcache2(int capacity) {
        this->_capacity = capacity;
        this->_count = 0;
    
        this->_head = this->_tail = this->_NOT_FOUND = this->_container.end();
    }
    
    int get(int key) {
        linkmap::iterator it = this->_container.find(key);

        if (it == this->_NOT_FOUND) {
            return -1;
        }
        else{
            // if this is end, nothing change
            /** else:
             connect parent and child, 
             check head,
             check tail
            */
            if (it != this->_tail) {
                // check head
                if (it == this->_head) {
                    this->_head = it->second->child;
                }
                this->_updateIterator(it);
            }
            return this->_tail->second->value;
        }
    }
    
    void set(int key, int value) {
        linkmap::iterator it = this->_container.find(key);
        if (it != this->_NOT_FOUND) {
            // in conatiner
            // if at end, do nothing
            /** else:
             update iterator
             */
            if (it != this->_tail) {
                this->_updateIterator(it);
            }
            it->second->value = value;
        }
        else{
            // not in container
            // create a new iterator and push
            
            // kick out if necessary
            if (this->_count == this->_capacity) {
                this->_popIterator();
            }
            this->_container[key] = cellptr(new LRUcell(value));
            auto it = this->_container.find(key);
            this->_pushIterator(it);
        }
    }
};

#include <cassert>
int main(){

    LRUcache2 lru(2);
    const int _not_found = -1;
    
//    lru.set(1, 1);
//    lru.set(3, 3);
//    lru.set(5, 5);
//    lru.set(2, 2);
//    assert(lru.get(1) == _not_found);
//    lru.set(3, 3);
//    // lru: 5-2-3
//    lru.set(4, 4);
//    assert(lru.get(5) == _not_found);
//    
    /**
 3,[set(1,1),set(2,2),set(3,3),set(4,4),get(4),get(3),get(2),get(1),set(5,5),get(1),get(2),get(3),get(4),get(5)]
     */
    LRUcache2 lru2(3);
//    lru2.set(1, 1);
//    lru2.set(2, 2);
//    lru2.set(3, 3);
//    lru2.set(4, 4);
//    cout << lru2.get(4) << "\n";
//    cout << lru2.get(3) << "\n";
//    cout << lru2.get(2) << "\n";
//    cout << lru2.get(1) << "\n";
//    lru2.set(5, 5);
//    cout << lru2.get(1) << "\n";
//    cout << lru2.get(2) << "\n";
//    cout << lru2.get(3) << "\n";
//    cout << lru2.get(4) << "\n";
//    cout << lru2.get(5) << "\n";
    
    lru.set(2, 1);
    lru.set(2, 2);
    cout << lru.get(2) << " ::\n";
    lru.set(1, 1);
    lru.set(4, 1);
    cout << lru.get(2) << " ::\n";
    printf("pass");
    return 0;
}