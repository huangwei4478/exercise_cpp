//
//  main.cpp
//  duality_public_inheritance
//
//  Created by huangwei on 2019/6/30.
//  Copyright © 2019 huangwei. All rights reserved.
//

/**
 The Duality of Public inheritance:
 
    - Inheritance of Interface
    - Inheritance of Implementation
 */

#include <iostream>

class Dog {
public:
  virtual void bark() = 0;
  void run() { std::cout << "I am running."; }
  virtual void eat() { std::cout << "I am eating. "; }
protected:
  void sleep() { std::cout << "I am sleeping. "; }
};

class Yellodog: public Dog {
public:
  virtual void bark() { std::cout << "I am a yellow dog.\n"; }
  void iSleep() { sleep(); }
};

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}
