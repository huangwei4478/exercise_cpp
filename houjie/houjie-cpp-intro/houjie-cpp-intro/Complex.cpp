//
//  Complex.cpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/11.
//

#include "Complex.hpp"
#include <iostream>

complex& __doapl(complex* ths, const complex& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

std::ostream& operator <<(std::ostream& out, const complex& r) {
    out << "real = " << r.real() << " img = " << r.imag();
    return out;
}

complex &complex::operator+=(const complex &r) {
    return __doapl(this, r);
}
