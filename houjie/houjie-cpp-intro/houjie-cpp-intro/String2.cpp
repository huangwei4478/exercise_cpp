//
//  String2.cpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/23.
//

#include "String2.hpp"
#include <cstring>

String2::String2(const char *cstr) {
    if (cstr) {
        size_t size = strlen(cstr);
        m_data = new char[size + 1];
        strncpy(m_data, cstr, size);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

String2::String2(const String2 &str) {
    size_t size = strlen(str.m_data);
    m_data = new char[size + 1];
    strncpy(m_data, str.m_data, size);
}

String2& String2::operator=(const String2 &str) {
    if (this == &str) {
        return *this;
    }
    
    delete [] m_data;
    size_t size = strlen(str.m_data);
    m_data = new char[size + 1];
    strncpy(m_data, str.m_data, size);
    return *this;
}

String2::~String2() { 
    delete [] m_data;
}

std::ostream& operator<<(std::ostream& os, const String2& str) {
    os << str.get_c_str();
    return os;
}
