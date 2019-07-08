//
//  exercise_14.cpp
//  Chapter-03
//
//  Created by huangwei on 2019/4/20.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>



int main() {
    std::vector<int> iv;
    int i;
    while (std::cin >> i) {
        iv.push_back(i);
    }
    
    for (const auto & k : iv) {
        std::cout << k << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : v) {
        i *= i;
    }
    
    for (const auto &i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
