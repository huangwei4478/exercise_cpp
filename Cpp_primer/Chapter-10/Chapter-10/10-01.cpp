//
//  10.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int val;
  cin >> val;
  
  vector<int> vi;
  
  for (int i; cin >> i; vi.push_back(i)) { }
  
  cout << "Value \"" << val << "\" occurs "
        << count(vi.begin(), vi.end(), val) << " time(s) in sequence."
        << endl;
  
  return 0;
}


