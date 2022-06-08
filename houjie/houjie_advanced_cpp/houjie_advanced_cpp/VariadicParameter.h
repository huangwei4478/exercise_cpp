//
//  VariadicParameter.h
//  houjie_advanced_cpp
//
//  Created by 黄炜 on 2022/6/8.
//

#ifndef VariadicParameter_h
#define VariadicParameter_h

#include <iostream>

template <typename T>
T adder(T v) {
    return v;
}

template <typename T, typename... Args>
T adder(T first, Args... args) {
    return first + adder(args...);
}

// This function with no parameter is absolute-needed
void print() {
    
}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
    std::cout << firstArg << " " << sizeof...(args) << std::endl;
    print(args...);
}
#endif /* VariadicParameter_h */
