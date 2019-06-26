//
//  main.cpp
//  RVal
//
//  Created by wei on 2019/6/25.
//  Copyright © 2019 wei. All rights reserved.
//

/**
 video from 'Bo C++', https://www.youtube.com/watch?v=IOkgBrXCtfo&t=1s
 C++ 11: Rvalue Reference
    1. Moving Semantics
    2. Perfect Forwading
 */

#include <iostream>
#include <vector>

using namespace std;

void printInt(int& i) { cout << "lvalue reference: " << i << endl; }
void printInt(int&& i) { cout << "rvalue reference: " << i << endl; }

class boVector {
    int size;
    double* arr_;           // big array
    
    public:
    boVector(const boVector& rhs) {         // Copy constructor
        size = rhs.size;
        arr_  = new double[size];
        for (int i = 0; i < size; ++i) { arr_[i] = rhs.arr_[i]; }
    }
    
    boVector(boVector&& rhs) {              // Move constructor
        size = rhs.size;
        arr_ = rhs.arr_;        // do not create a new array, just use it
        rhs.arr_ = nullptr;     // nil out the pointer, just in case the destructor destory this array
    }
    
    ~boVector() { delete [] arr_; }
};

void foo(boVector v);

boVector createBoVector();          // Creates a boVector


int main(int argc, const char * argv[]) {
    boVector reusable = createBoVector();
    
    foo(reusable);                  // invoke expensive copy constructor inside
    
    foo(createBoVector());          // invoke costly copy constructor inside, and the temp value is destoryed
    
    
}
