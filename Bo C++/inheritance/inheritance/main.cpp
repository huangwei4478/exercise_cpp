//
//  main.cpp
//  inheritance
//
//  Created by huangwei on 2019/6/29.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>

class Entity {
public:
  float X, Y;
  void Move(float xa, float ya) {
    X += xa;
    Y += ya;
  }
};

class Player : public Entity {
  const char* Name;
  
  void PrintName() {
    std::cout << Name << std::endl;
  }
};

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}
