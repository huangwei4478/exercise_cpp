//
//  10-03.cpp
//  Chapter-10
//
//  Created by huangwei on 2019/6/8.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  vector<int> vi;
  for (int i; cin >> i; vi.push_back(i)) {
    cout << "The sum of the sequence is"
        << accumulate(vi.cbegin(), vi.cend(), 0) << endl;
  }
}
