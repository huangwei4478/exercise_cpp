//
//  10-06.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main() {
  vector<int> vi(10, 1);
  vector<int> li(10, 1);
  fill_n(vi.begin(), vi.size(), 0);
  fill_n(li.begin(), li.size(), 0);
  
  
}
