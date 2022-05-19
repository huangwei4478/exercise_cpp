//
//  main.cpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/11.
//

#include <iostream>
#include "Complex.hpp"

int main(int argc, const char * argv[]) {
    complex c1(2, 3);
    complex c2(1, 2);
    
    std::cout << c1 << std::endl;
    std::cout << (c1 += c2) << std::endl;
    return 0;
}
