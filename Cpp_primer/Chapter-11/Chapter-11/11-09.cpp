//
//  11-09.cpp
//  Chapter-11
//
//  Created by huangwei on 2019/6/9.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <map>
#include <list>
#include <string>
#include <iostream>

using namespace std;

int main() {
  map<string, list<int>> words {
    {"ghi", {100, 200}, {"abc", {1, 3, 5}, { "def", {2, 4}}}}
  };
  
  for (const auto &w : words) {
//    cout << w.first
  }
}
