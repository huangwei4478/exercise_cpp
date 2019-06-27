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

void foo( boVector arg );
// boVector has both move constructor and copy constructor

boVector createBoVector();

template< typename T >
void relay( T arg ) {
    foo(arg);
}

int main() {
    boVector reusable = createBoVector();
    relay(reusable);
    
    relay(createBoVector());
}

/**
 1. No costly and unnecessary copy construction of boVector is made;
 2. rvalue is forwarded as rvalue, and lvalue is forwarded as lvalue;
 */

// Solution

template< typename  T >
void relay( T&& arg ) {
    foo( std::forward<T>( arg ) );
}

/**
 Reference Collapsing Rule ( C++ 11 ):
 1. T& &   --> T&
 2. T& &&  --> T&
 3. T&& &  --> T&
 4. T&& && --> T&&

 */

//template < class T >
//struct remove_reference;                            // It removes reference on type T
//
//// T is int&
//remove_reference<int&>::type i;                     // int i;
//
//// T is int
//remove_reference<int>::type i;                      // int i;

/**
    relay(9) => T = int&& => T&& = int && && = int &&
 
    relay(x) => T = int& => T&& = int& && = int&
 */

/**
 T&& is Universal Reference: rvalue, lvalue, const, non-const, etc...
 Conditions:
 1. T is a template type
 2. Type deduction (reference collapsing) happens to T
    - T is a function template type, not class template type
 
 */

// Implementation  of std::forward()
template<class T>
T&& forward(typename remove_reference<T>::type& arg) {
    return static_cast<T&&>(arg);
}

// std::move() vs std::forward()
// std::move<T>(arg);                      // turn arg into an rvalue type
// std::forward<T>(arg);                   // turn arg to type of T&&
