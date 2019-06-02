//
//  9-4.cpp
//  Chapter-04
//
//  Created by huangwei on 2019/6/2.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <vector>
#include <iostream>
#include <sstream>

bool hasValue(std::vector<int>::const_iterator begin,
              std::vector<int>::const_iterator end,
              int k) {
  for (auto it = begin; it != end; ++it) {
    if (k == *it) {
      return true;
    }
  }
  
  return false;
}
