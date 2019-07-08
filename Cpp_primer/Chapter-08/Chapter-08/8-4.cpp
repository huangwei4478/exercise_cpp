//
//  8-4.cpp
//  Chapter-08
//
//  Created by huangwei on 2019/6/2.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> read(const std::string &filename) {
  std::ifstream in(filename);
  std::vector<std::string> vs;
  
  if (in) {
    for (std::string s; std::getline(in, s); ) {
      vs.push_back(s);
    }
  } else {
    std::cerr << "fail to open files: " << filename << std::endl;
  }
  
  return vs;
}


