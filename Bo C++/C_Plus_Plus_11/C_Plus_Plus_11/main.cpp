//
//  main.cpp
//  C_Plus_Plus_11
//
//  Created by wei on 2019/6/26.
//  Copyright © 2019 wei. All rights reserved.
//

// C++ 11
#include <vector>
using namespace std;

vector<int> v = {3, 4, 5, 6};                       // Calling initializer_list constructor

// Define your own initializer_list constructor:

#include <initializer_list>
class boVector {
    vector<int> m_vec;
public:
    boVector(const initializer_list<int>& v) {
        for (initializer_list<int>::iterator itr = v.begin(); itr != v.end(); ++ itr) {
            m_vec.push_back(*itr);
        }
    }
};

boVector v2 = { 0, 2, 3, 4 };
boVector v3{0, 2, 3, 4};            // effectively the same

/**
    2. Uniform Initialization
 */


class dog {
public:
    int age;                                            // 3rd choice
    
    dog(int a) {                                        // 2nd choice
        age = a;
    }
    
    dog(const initializer_list<int>& vec) {             // 1st choice
        age = *(vec.begin());
    }
};
dog d1{3};

// Enum Class

enum class apple {green, red};
enum class orange {big, small};

// static assert
static_assert(sizeof(int) == 4, "int is not 4 bytes");


// delegating constructor
class dog2 {
public:
    dog2() { }
    dog2(int a): dog2() { }
};



