//
//  move_semantics.cpp
//  RVal
//
//  Created by wei on 2019/6/26.
//  Copyright © 2019 wei. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

class Widget {
public:
    const size_t numElems = 100000;
    Widget()
    : mPtr(new int[numElems]) {}
    
    Widget(const Widget &other)
    : mPtr(new int[numElems]) {                 // a costly copy constructor
        memcpy(mPtr, other.mPtr, sizeof(int) * numElems);
    }
    
    Widget(Widget &&other)                      // a move constructor
    : mPtr(other.mPtr) {
        other.mPtr = nullptr;
    }
    
    ~Widget() {
        delete [] mPtr;
    }
    
    Widget &operator =(const Widget &other) {
        if (this == &other) {
            return *this;
        }
        
        memcpy(mPtr, other.mPtr, sizeof(int) * numElems);
        return *this;
    }
    
    Widget &operator =(Widget &&other) {
        if (this == &other) {
            return *this;
        }
        
        std::cout << "MOVE opr" << std::endl;
        mPtr = other.mPtr;
        other.mPtr = nullptr;
        
        return *this;
    }
    
    bool operator <(const Widget &other) const {
        return std::less<const Widget *>()(this, &other);
    }
    
private:
    int *mPtr;
};

int main() {
    std::vector<Widget> v(5);
    
    std::sort(std::begin(v), std::end(v));
    
    std::string s = "abc";
    std::string s2 = std::move(s);
    
    

    return 0;
}
