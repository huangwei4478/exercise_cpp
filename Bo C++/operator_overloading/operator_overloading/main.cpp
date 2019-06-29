//
//  main.cpp
//  operator_overloading
//
//  Created by huangwei on 2019/6/29.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <string>

struct Vector2 {
  float x, y;
  Vector2(float x, float y) : x(x), y(y) {}
  
  Vector2 Add(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
  }
  
  Vector2 operator+(const Vector2& other) const {
    return Add(other);
  }
};

int main(int argc, const char * argv[]) {
  
  Vector2 position(4.0f, 4.0f);
  Vector2 speed(0.5f, 1.5f);
  
  Vector2 result = position.Add(speed);
  
  Vector2 result2 = position + speed;
  
  return 0;
}
