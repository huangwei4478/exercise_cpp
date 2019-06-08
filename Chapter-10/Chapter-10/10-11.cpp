//
//  10-11.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

ostream &print(ostream &os, const vector<string> &vs) {
  for (const auto &i: vs) {
    os << i << " ";
  }
  
  return os;
}

void elimDups(vector<string> &words) {
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
  
}
