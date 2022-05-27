//
//  main.cpp
//  houjie_advanced_cpp
//
//  Created by 黄炜 on 2022/5/27.
//

#include <iostream>
#include "Convertion/Fraction.h"

int main(int argc, const char * argv[]) {
    Fraction f(3, 5);
    double d = 4 + f;
    std::cout << d << std::endl;
    return 0;
}
