//
//  main.cpp
//  multiple_inheritance
//
//  Created by huangwei on 2019/6/30.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>

//class InputFile {
//public:
//  void read();
//  void open();
//};
//
//class OutputFile {
//public:
//  void write();
//  void open();
//};
//
//class IOFile : public InputFile, public OutputFile {
//  // both for reading and writing a file
//};


class File {
public:
  std::string name;
  void open() {}
  File(std::string fname) : name(fname) {}
};

class InputFile2 : virtual public File {
  // only need one instance of name & open()
public:
  InputFile2(std::string fname) : File(fname) {}
};

class OutputFile2 : virtual public File {
  // only need one instance of name & open()
public:
  OutputFile2(std::string fname) : File(fname) {}
};

class IOFile2 : public InputFile2, public OutputFile2 {
public:
  // Diamond shape of hierarchy
  IOFile2(std::string fname) : OutputFile2(fname), InputFile2(fname), File(fname) {}
};

int main(int argc, const char * argv[]) {
  
//  IOFile f;
//  f.open();       // which one?
//  f.OutputFile::open();   // specify one
  
  IOFile2 f2("hahaha");
//  f2.open;
  f2.open();
  
  return 0;
}

/**
  Interface Segregation Principle
 
  Split large interfaces into smaller and more specific ones so that clients
  only need to know about the methods that are of interest to them.
 
 */

/**
  How to avoid all the mess that multiple inheritance brought to us?
 
  use Pure Abstract Classes!
 
 Abstract class: A class that has one or more pure virtual function
 
 Pure Abstract Classes:
    - A class containing only pure virtual functions
        - no data
        - no concrete functions
 */

class OutputFile3 {
public:
  virtual void write() = 0;
  virtual void open() = 0;
};

