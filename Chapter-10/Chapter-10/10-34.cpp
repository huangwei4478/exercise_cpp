//
//  10-34.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> vi{0, 1, 2, 3, 4, 5};
  for (auto it = vi.crbegin(); it != vi.crend; ++it) {
    cout << *it << " ";
  }
  cout << endl;
}
