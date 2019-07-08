//
//  10-13.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool longStr(const string &s) {
  return s.size() >= 5;
}

int main() {
  vector<string> words;
  for (string s; cin >> s; words.push_back(s)) {
    
  }
  
  auto long_bg = std::partition(words.begin(), words.end(), longStr);
  for (auto it = words.begin(); it != long_bg; ++it) {
    cout << *it << " ";
  }
  cout << endl;
}
