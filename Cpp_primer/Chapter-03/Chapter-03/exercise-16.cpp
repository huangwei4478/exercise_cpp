//
//  exercise-16.cpp
//  Chapter-03
//
//  Created by huangwei on 2019/4/20.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

void print_vector_int(const vector<int> &v) {
    for (const auto &elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print_vector_int_iter(const vector<int> &v) {
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void print_vector_string(const vector<string> &v) {
    for (const auto &elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print_vector_string_iter(const vector<string> &v) {
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    vector<int> v1;                 // 0 elements
    vector<int> v2(10);             // 10 elements, values are all 0
    vector<int> v3(10, 42);         // 10 elements, values are all 42
    vector<int> v4{10};             // 1 elements, value is 10
    vector<int> v5{10, 42};         // 2 elements, values are 10 and 42
    vector<string> v6{10};          // 10 elements, values are all empty string
    vector<string> v7{10, "hi"};    // 10 elements, values are all "hi"
    
    return 0;
}
