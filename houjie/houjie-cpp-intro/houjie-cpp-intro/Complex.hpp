//
//  Complex.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/11.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <cmath>
#include <iostream>

class complex {
public:
    complex(double r = 0, double i = 0): re(r), im(i) {}
    double real() const { return re; }
    double imag() const { return im; }
    friend std::ostream& operator<<(std::ostream&, const complex&);
    complex& operator+=(const complex&);
private:
    double re, im;
    friend complex& __doapl(complex*, const complex&);
};


#endif /* Complex_hpp */
