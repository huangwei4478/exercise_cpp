//
//  main.cpp
//  vertual_destructors
//
//  Created by huangwei on 2019/6/29.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>

class Base {
public:
  Base() { std::cout << "Base Constructor\n"; }
  virtual ~Base() { std::cout << "Base Destructor\n"; } // 100% sure to mark destructor of base class as 'virtual'
};

class Derived : public Base {
public:
  Derived() { std::cout << "Derived Constructor\n"; }
  ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main(int argc, const char * argv[]) {
  Base *base = new Base();
  delete base;
  std::cout << "------------------------" << std::endl;
  
  Derived *derived = new Derived();
  delete derived;
  
  std::cout << "------------------------" << std::endl;

  // Problematic: only Base destructor is called
  Base *poly = new Derived();
  delete poly;
  
  return 0;
}

/**
 Note 1: use shared pointer to avoid this
 
 Note 2: All classes in STL have no virtual destructor, so be careful
         inheriting from them.
 */
