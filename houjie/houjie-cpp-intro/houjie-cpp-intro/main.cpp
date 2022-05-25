//
//  main.cpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/11.
//

#include <iostream>
#include "Complex.hpp"
#include "String2.hpp"
#include "Queue.hpp"

int main(int argc, const char * argv[]) {
    complex c1(2, 3);
    complex c2(1, 2);
    
    std::cout << c1 << std::endl;
    std::cout << (c1 += c2) << std::endl;
    
    String2 s1("Hello World!");
    String2 s2(s1);
    String2 s3;
    s3 = s2;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    return 0;
}
