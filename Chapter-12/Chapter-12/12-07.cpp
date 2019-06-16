//
//  12-07.cpp
//  Chapter-12
//
//  Created by huangwei on 2019/6/16.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

typedef shared_ptr<vector<int>> share_vec_ptr;

share_vec_ptr factory_veci() {
  return make_shared<vector<int>>();
}

void set_veci(share_vec_ptr vip) {
  for (int i; cin >> i; vip -> push_back(i)) { }
}

void print_veci(share_vec_ptr vip) {
  for (const auto &i : *vip) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  auto p = factory_veci();
  set_veci(p);
  print_veci(p);
  
  return 0;
}
