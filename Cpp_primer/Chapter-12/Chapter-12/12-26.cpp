//
//  12-26.cpp
//  Chapter-12
//
//  Created by huangwei on 2019/6/16.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <string>
#include <iostream>
#include <memory>

using namespace std;

int main() {
  allocator<string> alloc;
  constexpr size_t n = 10;
  
  auto const p = alloc.allocate(n);     // string *const p
  
  string s;
  
  auto q = p;   // string *q
  
  while (cin >> s && q != p + n) {
    alloc.construct(q++, s);
  }
  
  const size_t sz = q - p;              // size
  
  for (auto pos = p; pos != q; ++pos) {
    cout << *pos << endl;
  }
  
  while (q != p) {
    alloc.destroy(--q);
  }
  
  alloc.deallocate(p, n);
}
