//
//  Fraction.h
//  houjie_advanced_cpp
//
//  Created by 黄炜 on 2022/5/27.
//

#ifndef Fraction_h
#define Fraction_h

class Fraction {
public:
    Fraction(int num, int den = 1): m_numerator{ num }, m_denominator{ den } {}
    operator double() const {
        return (double)((double)m_numerator / (double)m_denominator);
    }
private:
    int m_numerator;            // 分子
    int m_denominator;          // 分母
};

#endif /* Fraction_h */
