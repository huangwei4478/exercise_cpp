//
//  main.cpp
//  Chapter-06
//
//  Created by huangwei on 2019/5/4.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
using namespace std;

void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
}

inline const string &shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2) {
    auto &r = shorterString(const_cast<const string &>(s1),
                            const_cast<const string &>(s2));
    return const_cast<string&>(r);
}

int main(int argc, const char * argv[]) {
    error_msg({"functionalX"});
    error_msg({"functionalX", "okay"});
    return 0;
}
