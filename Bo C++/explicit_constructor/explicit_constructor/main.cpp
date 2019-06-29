//
//  main.cpp
//  explicit_constructor
//
//  Created by huangwei on 2019/6/29.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <string>

class Entity {
private:
  std::string m_Name;
  int m_Age;
public:
  explicit Entity(const std::string & name) : m_Name(name), m_Age(-1) {}
  explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity) {
  // Printing
}

int main(int argc, const char * argv[]) {
  
  Entity a("Cherno");
  Entity b(22);
  
  // weird ...
  // Implicit conversion
  Entity a1 = std::string("Cherno");
  Entity b1 = 22;
  
  // this is also a implicit conversion
  PrintEntity(22);
  PrintEntity(std::string("Cherno"));
  
  
  return 0;
}
