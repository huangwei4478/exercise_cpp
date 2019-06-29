//
//  main.cpp
//  interfaces
//
//  Created by huangwei on 2019/6/29.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <string>

class Printable {
public:
  virtual std::string GetClassName() = 0;
};

class Entity: public Printable {
public:
  virtual std::string GetName() = 0;
  std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
private:
  std::string m_Name;
public:
  Player(const std::string &name) : m_Name(name) {}
  
  std::string GetName() override { return m_Name; }
  std::string GetClassName() override { return "Player"; }
  
};

void Print(Printable *obj) {
  std::cout << obj -> GetClassName() << std::endl;
}

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}
