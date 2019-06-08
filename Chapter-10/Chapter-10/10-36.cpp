//
//  10-36.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> vi{ 0, 1, 2, 3, 4, 5} ;
  auto rit = find(vi.crbegin(),vi.crend(), 0);
  cout << " the last " << *rit << " in vector is at position "
  << rit.base() - vi.cbegin() - 1 << endl;
  
  return 0;
}


