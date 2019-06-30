//
//  main.cpp
//  public_protected_private_inheritance
//
//  Created by huangwei on 2019/6/30.
//  Copyright © 2019 huangwei. All rights reserved.
//

#include <iostream>

/**
 Access control:
    1. None of the derived classes can access anything that is private in B.
    2. D_pub inherits public members of B as public and the protected members of B as protected
    3. D_priv inherits the public and protected members of B as private.
    4. D_prot inherits the public and protected members of B as protected.
 
 Casting:
    1. Anyone can cast a D_pub* to B*, D_pub is a special kind of B. (is-a relationship)
    2. D_priv's members and friends can cast a D_priv* to B*. (
    3. D_prot's members, friends, and children can cast a D_prot* to B*
 */

class B {
public:
  void f_pub() { std::cout << "f_pub is called.\n"; }
protected:
  void f_prot() { std::cout << "f_prot is called.\n"; }
private:
  void f_priv() { std::cout << "f_priv is called.\n"; }
};

class D_pub : public B {
public:
  void f() {
    f_pub();            // OK, D_pub's public function
    f_prot();           // OK, D_pub's protected function
//    f_priv();           // Error. B's private function
  }
};

class D_prot : protected B {
public:
  using B::f_pub;
  void f() {
    f_pub();            // OK, D_prot's protected function
    f_prot();           // OK, D_prot's protected function
//    f_priv();           // Error. B's private function
  }
};

class D_priv : private B {
public:
  void f() {
    f_pub();            // OK, D_priv's private function
    f_prot();           // OK, D_priv's private function
//    f_priv();           // Error, B's private function
  }
};

/**
 public inheritance: is-a relationship, eg. D_pub is-a kind of a B
 
 private inheritance: similar to has-a relation
 
 */

class ring {
public:
  void tinkle() {}
};

// Composition
class dog {
  ring m_ring;
public:
  void tinkle() { m_ring.tinkle(); }        // call forwarding
};

// Private Inheritance
class dog2 : private ring {
public:
  using ring::tinkle;
};

// Composition is more flexible;

// rare case: ring has a virtual function, and inside the member function , the virtual function is called
//

int main(int argc, const char * argv[]) {
  
  D_pub D1;
  D1.f_pub();           // OK, f_pub() is D_pub's public function
  
  D_prot D2;
  D2.f_pub();           // Error. f_pub() is D_prot's protected function
                        // add using B::f_pub, this error would dismiss
  
  B* pB = &D1;          // OK
//  pB = &D2;             // Error
  
  return 0;
}
