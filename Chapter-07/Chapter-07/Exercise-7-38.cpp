//
//  Exercise-7-38.cpp
//  Chapter-07
//
//  Created by huangwei on 2019/5/26.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);
  
public:
  Sales_data(const std::string &no): bookNo(no) {}
  Sales_data(const std::string &no, unsigned us, double price): bookNo(no), units_sold(us), revenue(price * us) {}
  Sales_data(std::istream &is = std::cin) { read(is, *this); }
  
private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
