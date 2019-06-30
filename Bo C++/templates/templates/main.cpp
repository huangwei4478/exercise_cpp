//
//  main.cpp
//  templates
//
//  Created by huangwei on 2019/6/30.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <string>

// A compile-time stack array with custom size
template <typename T, int N>
class Array {
private:
  T m_Array[N];
public:
  int GetSize() const { return N; }
};


int main(int argc, const char * argv[]) {
  Array<int, 5> array;
  std::cout << array.GetSize() << std::endl;
  
  return 0;
}
