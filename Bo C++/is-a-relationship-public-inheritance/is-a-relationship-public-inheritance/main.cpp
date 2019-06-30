//
//  main.cpp
//  is-a-relationship-public-inheritance
//
//  Created by huangwei on 2019/6/30.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>

/**
  Public inheritance => "is-a" relation
  A derived class should be able to do everything the base class can do
 */

class bird {
};

class flyableBird : public bird {
public:
  void fly();
};

class penguin : public flyableBird {
  
};

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}
