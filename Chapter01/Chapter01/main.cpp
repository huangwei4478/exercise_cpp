//
//  main.cpp
//  Chapter01
//
//  Created by huangwei on 2019/4/14.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

void TaylorSeries() {
    double x = 2.0, xn = 1.0, exp_x = 1.0;
    unsigned long fac = 1;
    for (unsigned long i = 1; i <= 10; i++) {
        xn *= x;
        fac *= i;
        exp_x += xn / fac;
        std::cout << "e^x is " << exp_x << '\n';
    }
}

double two_norm(const std::hecto& v) { return 0.0; }

inline double square(double x) { return x * x; }

void f(int x) {}
void f(int& x) {}
void f(const int& x) {}

int main(int argc, const char * argv[]) {
    std::string s2 = "In C++ better like this";
    std::string s3 = "This is a very long and clumsy text "
    "This is too long for one line";
    
    long l2 = 123345657568;
    
    // Error: too large!
    //    long l3 = {127653724876328746823764823646};
    int i1 = 3.14;
    //    int i2 = {3.14};
    
    unsigned u2 = -3;
    //    unsigned u2n = {-3};
    return 0;
}
