//
//  main.cpp
//  weak_pointer
//
//  Created by wei on 2019/6/27.
//  Copyright © 2019 wei. All rights reserved.
//

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// weak_ptr has no ownership of the pointed object.
// like a raw pointer somehow
// weak_ptr cannot be deleted if pointed object is released
// weak_ptr == nullptr
// safer access of the pointer

class Dog {
    weak_ptr<Dog> m_pFriend;
public:
    string m_name;
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    Dog(string name) { cout << "Dog is created: " << name << endl; m_name = name; }
    ~Dog() { cout << "dog is destroyed:" << m_name << endl; }
    void makeFriend(shared_ptr<Dog> f) { m_pFriend = f; }
    void showFriend() {
        if (!m_pFriend.expired()) cout << "My friend is: " << m_pFriend.lock() -> m_name << endl;
        cout << " He is owned by " << m_pFriend.use_count() << " pointers." << endl;
    }
};


int main(int argc, const char * argv[]) {
    shared_ptr<Dog> pD(new Dog("Gunner"));
    shared_ptr<Dog> pD2(new Dog("Smokey"));
    pD -> makeFriend(pD2);
    pD2 -> makeFriend(pD);                      // cyclic reference
    pD -> showFriend();
    return 0;
}
