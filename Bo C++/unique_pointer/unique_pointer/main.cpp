//
//  main.cpp
//  unique_pointer
//
//  Created by wei on 2019/6/27.
//  Copyright © 2019 wei. All rights reserved.
//

// Unique Pointers: exclusive ownership, light weight smart pointer

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Bone {};

class Dog {
public:
    string m_name;
//    Bone* pB;
    unique_ptr<Bone> pB;            // this prevents memory leak even constructor fails
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    Dog() { pB = unique_ptr<Bone>(new Bone()); cout << "Nameless dog created" << endl; m_name = "nameless"; }
    Dog(string name) { cout << "Dog is created: " << name << endl; m_name = name; }
    ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
};

void f(unique_ptr<Dog> p) {
    p->bark();
}

unique_ptr<Dog> getDog() {
    unique_ptr<Dog> p(new Dog("Smokey"));
    return p;
}

void test() {
    unique_ptr<Dog> pD(new Dog("Gunner"));
//    unique_ptr<Dog> pD2(new Dog("Smokey"));
//
//    pD2->bark();
//    pD2 = move(pD);
//    // 1. Smokey is destroyed
//    // 2. pD becomes empty
//    // 3. pD2 owns Gunner
//    pD2->bark();
    f(move(pD));

    unique_ptr<Dog> pD2 = getDog();                 // move semantics is automatically applied
    
    unique_ptr<Dog[]> dogs(new Dog[3]);             // all three dogs are destroyed, and do not need a custom deleter
    
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
