//
//  12-14.cpp
//  Chapter-12
//
//  Created by huangwei on 2019/6/16.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <memory>
#include <iostream>

using namespace std;

struct destination {
  unsigned id;
  explicit destination(unsigned des_id = 0) : id(des_id) {}
};

struct connection {
  destination *dest;
};

connection connect(destination *dest) {
  connection new_conn;
  new_conn.dest = dest;
  cout << "Setup connection to" << new_conn.dest -> id << endl;
  return new_conn;
}

void disconnect(connection conn) {
  cout << "Stop connection to" << conn.dest -> id << endl;
  conn.dest = nullptr;
}

void end_connection(connection *p) {
  disconnect(*p);
}

void f(destination &d) {
  connection c = connect(&d);
  shared_ptr<connection> p(&c, end_connection);
  cout << "Using connection" << c.dest -> id << endl;
}

int main() {
  destination d(5);
  f(d);
  
  return 0;
}

