//
//  10-20.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
  int n;
  auto isZero = [&n] { return n > 0 ? static_cast<void>(--n), false : true; };
  
  cin >> n;
  
  while (!isZero()) {
    cout << n << endl;
  }
  isZero();
}
