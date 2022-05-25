//
//  String2.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/23.
//

#ifndef String2_hpp
#define String2_hpp
#include <iostream>

class String2 {
public:
    String2(const char* cstr = 0);
    String2(const String2& str);
    String2& operator=(const String2& str);
    virtual ~String2();
    const char* get_c_str() const { return m_data; }
private:
    char* m_data;
};

std::ostream& operator<<(std::ostream& os, const String2& str);

#endif /* String2_hpp */
