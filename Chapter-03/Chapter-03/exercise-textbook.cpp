//
//  exercise-textbook.cpp
//  Chapter-03
//
//  Created by huangwei on 2019/4/20.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <string>
using namespace std;

void stringIterator(void) {
    string s("Some string");
    
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }
}
