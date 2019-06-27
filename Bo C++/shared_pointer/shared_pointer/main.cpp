//
//  main.cpp
//  shared_pointer
//
//  Created by wei on 2019/6/27.
//  Copyright © 2019 wei. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>               // for smart pointer
using namespace std;

class Dog {
    string name_;
public:
    Dog(string name) { cout << "Dog is created: " << name << endl; name_ = name; }
    Dog() { cout << "Nameless dog created." << endl; name_ = "nameless"; }
    ~Dog() { cout << "dog is destroyed: " << name_ << endl; }
    void bark() { cout << "Dog " << name_ << " rules!" << endl; }
};

//void foo() {
//    Dog *p = new Dog("Gunner");
//    // ...
//    delete p;
//
//    // ...
//
//    p -> bark();        // p is a dangling pointer - undefined behavior
//}

void foo() {
    shared_ptr<Dog> p(new Dog("Gunner"));           // reference count == 1
    p -> bark();
    
    {
        shared_ptr<Dog> p2 = p;     // reference count == 2
    }   // reference count == 1
    
}       // reference count == 0, Dog will be destroyed

int main(int argc, const char * argv[]) {
    foo();
    
//    // ... such a bad idea
//    Dog* d = new Dog("Tank");
//    shared_ptr<Dog> p(d);               // p.use_count() == 1
//    shared_ptr<Dog> p2(d);              // p2.use_count() == 1
//
    // instance d would be destoryed twice, which would bring undefined behavior
    
    // An object should be assign to a smart pointer as soon as it is created
    // Raw pointer should not be used again.
    
    // short cut for convenience, Raw pointer => Smart pointer
    shared_ptr<Dog> p = make_shared<Dog>("Tank");   // faster & safer
    (*p).bark();
    p -> bark();
    
    // static_pointer_cast
    // dynamic_pointer_cast
    // const_pointer_cast
    
    return 0;
}
