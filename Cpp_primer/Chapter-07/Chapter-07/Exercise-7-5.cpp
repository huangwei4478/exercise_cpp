//
//  Exercise-7-5.cpp
//  Chapter-07
//
//  Created by huangwei on 2019/5/26.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ConstRef {
public:
  ConstRef(int ii);
private:
  int i;
  const int ci;
  int &ri;
};

//ConstRef::ConstRef(int ii) {
//  i = ii;
//  ci = ii;
//  ri = i;
//}

ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) {  }
