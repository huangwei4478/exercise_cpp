//
//  10-30.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
  istream_iterator<int> i_iter(cin), i_eof;
  
  vector<int> vi(i_iter, i_eof);
  sort(vi.begin(), vi.end());
  ostream_iterator<int> o_iter(cout, " ");
  copy(vi.begin(), vi.end(), o_iter);
  return 0;
}

