//
//  A.h
//  Cpp_template
//
//  Created by wei on 2022/7/5.
//

#ifndef A_h
#define A_h

template <int i>
class A {
    public void foo(int) {}
};

template <uint8_t a, typename b, void* c> class B {};
template <bool, void (*a) ()> class C {};
template <void (A<3>::*a)(int)> class D {};

template <int i> int Add(int a) {
    return a + 1;
}

void foo() {
    A<5> a;
    B<7, A<5>, nullptr> b;
    C<false, &foo> c;
    
}

#endif /* A_h */
