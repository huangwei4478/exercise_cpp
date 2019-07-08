//
//  10-14.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
  auto sum = [](int a, int b) { return a + b; };
  
  int a, b;
  cin >> a >> b;
  cout << a << " + " << b << " = " << sum(a, b) << endl;
  
  return 0;
}
