//
//  main.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
  int ia[] = { 27, 210, 12, 47, 109, 83 };
  int val = 83;
  int* result = find(begin(ia), end(ia), val);
  printf("%d", *result);
//  return 0;
}
