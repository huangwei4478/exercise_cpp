//
//  14-6.cpp
//  Chapter-14
//
//  Created by huangwei on 2019/6/29.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#define USE_OPERATOR

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream, Sales_data &);
  
#ifndef USE_OPERATOR
  friend std::ostream &print(std::ostream &, const Sales_data &);
#else
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);
#endif

public:
  Sales_data() : Sales_data("", 0, 0.0) {}
  explicit Sales_data(const std::string &no):
  Sales_data(const std::string &no, unsigned us, double price) : bookNo(no), units_sold(us), revenue(price *us) {}
  explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }
private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  
};
