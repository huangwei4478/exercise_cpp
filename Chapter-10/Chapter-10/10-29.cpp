//
//  10-29.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  string filename;
  cin >> filename;
  
  ifstream in(filename);
  
  if (!in.is_open()) {
    cerr << "Can not open file: " << filename << endl;
    return -1;
  }
  
  istream_iterator<string> iter(in), eof;
  vector<string> vs(iter, eof);
  for (const auto &s: vs) {
    cout << s << endl;
  }
  
  return 0;
}
