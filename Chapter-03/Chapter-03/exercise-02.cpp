//
//  main.cpp
//  Chapter-03
//
//  Created by huangwei on 2019/4/20.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <string>

void read_lines() {
    std::string line;
    while (getline(std::cin, line)) {
        std::cout << line << std::endl;
    }
}

void read_words() {
    std::string word;
    while (std::cin >> word) {
        std::cout << word << std::endl;
    }
}

//int main(int argc, const char * argv[]) {
//    read_lines();
//    read_words();
//    return 0;
//}
