//
//  main.cpp
//  CppTemplateTutorial
//
//  Created by wei on 2019/7/1.
//  Copyright © 2019 wei. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <type_traits>
#include <complex>

template <typename T> class ClassA {
    T member;
};

template <typename T>
class vector {
public:
    void push_back(T const&);
    void clear();
    
private:
    T* elements;
};

template <typename T> void foo(T const& v);

template <typename T> T foo();

template <typename T> void foo();

template <typename T, typename U> U foo(T const&);

template <typename T> void foo() {
    T var;
}

template <typename T> T add(T a, T b) {
    return a + b;
}

float data[1024];

template <typename T> T GetValue(int i) {
    return static_cast<T>(data[i]);
}

template <typename SrcT, typename DstT> DstT c_style_cast(SrcT v) {
    return (DstT)(v);
}

template <typename T> class TemplateWithType;

template <int      V> class TemplateWithValue;

template <typename T, int Size> struct Array {
    T data[Size];
};

template <int i> class A {
public:
    void foo(int) {
        
    }
};

template <uint8_t a, typename b, void* c> class B {};
template <bool, void (*a)()> class C {};
template <void (A<3>::*a)(int)> class D {};

template <int i> int add_i(int a) {
    return a + i;                       // template-curry?
}

template <typename T>
class Stack {
public:
    void push(T v);
    T pop();
    T Find(T x);
};

typedef Stack<int> StackInt;
typedef Stack<float> StackFloat;

struct Variant {
    union {
        int x;
        float y;
    } data;
    uint32_t typeId;
};

Variant addFloatOrMulInt(Variant const* a, Variant const* b) {
    Variant ret;
    assert(a -> typeId == b -> typeId);
    if (a -> typeId == b -> typeId) {
        ret.data.x = a -> data.x * b -> data.x;
    } else {
        ret.data.y = a -> data.y + b -> data.y;
    }
    return ret;
}

#define BIN_OP(type, a, op, b, result) (*(type *)(result)) = (*(type const *)(a)) op (*(type const*)(b))

// Template 的特化

// 1. 写出模板的一般形式（原型）
template <typename T> class AddFloatOrMulInt {
    static T Do(T a, T b) {
        return T(0);
    }
};

// 2. 指定 T 是 int 时的代码
template <> class AddFloatOrMulInt<int> {
    static int Do(int a, int b) {
        return a * b;
    }
};

// 3. 指定 T 是 float 时候的代码
template <> class AddFloatOrMulInt<float> {
    static float Do(float a, float b) {
        return a + b;
    }
};

// template<>: 特化的时候，类型在后面已经提供了

// 用模板做一个 类型-数字 的对照表
template <typename T> class TypeToID {
public:
    static int const ID = -1;
};

template <> class TypeToID<uint32_t> {
public:
    static int const ID = 0;
};


/**
 运行时才知道void*的参数传错了
 而且转成了void*之后，指针原来的类型都丢失了
 */
void copy(void* dst,
          void const* src,
          size_t elemSize,
          size_t elemCount,
          void (*copyElem)(void *dstElem, void const* srcElem),
          void (*advancePointer)(void const *, size_t)) {
              void const* reader = src;
              void const* writer = dst;
              for (size_t i = 0; i < elemCount; ++i) {
                  copyElem((void *)writer, reader);
                  advancePointer(reader, elemSize);
                  advancePointer(writer, elemSize);
              }
}

/**
 用模板来匹配任意类型的指针，并且同时保留类型信息
 */

template <typename T>
void copy(T* dst, T const* src, size_t elemCount) {
    for (size_t i = 0; i < elemCount; ++i) {
        dst[i] = src[i];
    }
}

// 对指针类型特化，所以写成 T* （very impressive！）
template <typename T>
class TypeToID<T*> {
public:
    static int const ID = 0x80000000;
};

void printID() {
    std::cout << "ID to float*: " << TypeToID< float* >::ID << std::endl;
}

// 把指针类型的那个指针干掉
template <typename T>
class RemovePointer {
    // do nothing, just in case it is not a pointer-type
};

template <typename T>
class RemovePointer<T*> {
public:
    typedef T  Result;
};

void foo2() {
    RemovePointer<float*>::Result x = 5.0f;         // float* -> float
    std::cout << x << std::endl;
}

template <typename T> struct X {};
template <typename T> struct Y {
    typedef X<T> ReboundType;
    typedef typename X<T>::MemberType MemberType2;
//    typedef UnknownType MemberType3;                  // ERROR!
};

struct A2;
template <typename T> struct B2;
template <typename T> struct X2 {
    typedef X<T> _A;
//    typedef X _B;
//    typedef T _C;
    
    class Y {
        typedef X<T> _D;
//        typedef X<T>::T _E;
        typedef typename X<T*>::Y _F;
    };
    
//    typedef A _G;
//    typedef B<T> _H;
//    typedef typename B<T>::type _I;
//    typedef B<int>::type _J;
};

// Chapter 3 start

template <typename T> struct DoWork;                // prototype

template <> struct DoWork<int> {};                  // int
template <> struct DoWork<float> {};                // float
//template <> struct DoWork<int, int> {};             // int, int

template <typename U> struct DoWork<U*> {};           // 指针类型的偏特化

template <typename T, typename U> struct X3;
template <typename T> struct X3<T, T> {};
template <typename T> struct X3<T*, T> {};
template <typename T> struct X3<T, T*> {};
template <typename U> struct X3<U, int> {};
template <typename U> struct X3<U*, int> {};
template <typename T, typename U> struct X3<U*, T*> {};
template <typename U, typename T> struct X3<U, T*> {};

template <typename T> struct X3<std::unique_ptr<T>, std::shared_ptr<T>>;

template <typename T0, typename T1 = void> struct DoWork2;

template <typename T> struct DoWork2<T> {};

// Tuple 的声明，来自 boost
struct null_type;

template <
class T0 = null_type, class T1 = null_type, class T2 = null_type,
class T3 = null_type, class T4 = null_type, class T5 = null_type,
class T6 = null_type, class T7 = null_type, class T8 = null_type,
class T9 = null_type>
class tuple;

// C++ 11, Variadic Template
template <typename... Ts> class tuple2;

template <typename T> T CustomDiv(T lhs, T rhs) {
    return lhs / rhs;
}

// Gan！C++还可以这样写？
template <typename T, bool isFloat = std::is_floating_point<T>::value> struct SafeDivide {
    static T Do(T lhs, T rhs) {
        return CustomDiv(lhs, rhs);
    }
};

template <typename T> struct SafeDivide<T, true> {          // A
    static T Do(T lhs, T rhs) {
        return lhs / rhs;
    }
};

template <typename T> struct SafeDivide<T, false> {         // B
    static T Do(T lhs, T rhs) {
        return lhs;
    }
};

template <typename T> T CustomDiv2(T lhs, T rhs) {
    T v;
    return v;
}

// 真正的分派
template <typename T, typename Enabled = std::true_type> struct SafeDivide2 {
    static T Do(T lhs, T rhs) {
        return CustomDiv2(lhs, rhs);
    }
};

template <typename T> struct SafeDivide2<
    T, typename std::is_floating_point<T>::type> {
        static T Do(T lhs, T rhs) {
            return lhs / rhs;                               // 偏特化A
        }
    };

template <typename T> struct SafeDivide2<
    T, typename std::is_integral<T>::type> {
        static T Do(T lhs, T rhs) {
            return rhs == 0 ? 0 : (lhs / rhs);
        }
    };

void foo5() {
    SafeDivide2<float>::Do(1.0f, 2.0f);
    SafeDivide2<int>::Do(1, 2);
    SafeDivide2<std::complex<float>>::Do({1.f, 2.f}, {1.f, -2.f});
    
}

void foo4() {
    SafeDivide<float>::Do(1.0f, 2.0f);                      // Call A
    SafeDivide<int>::Do(1, 2);                              // Call B
}


// 3.2 后悔药 SFINAE
template <typename T, typename U>
void foo6(T t, typename U::type u) {
    
}

struct X4 {
    typedef float type;
};

template <typename T, typename U>
void foo7(T t, typename U::type u) {
    // ...
}

void callFoo() {
    foo7<int, X4>(5, 5.0);                       // T == int, typenamem U::type == X::type == float
}

struct ICounter {
    virtual void increase() = 0;
    virtual ~ICounter() {}
};

struct Counter: public ICounter {
    void increase() override {
        // implements
    }
};

template <typename T>
void inc_counter(T& counterObj,
typename std::enable_if<std::is_base_of<T, ICounter>::value>::type* = nullptr);

template <typename T>
void inc_counter(
    T& counterInt,
    typename std::enable_if<std::is_integral<T>::value>::type* = nullptr
);



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    X3<float*,  int>      v0;
    X3<double*, int>      v1;
    X3<double,  double>   v2;
    X3<float*,  double*>  v3;
//    X3<float*,  float*>   v4;
    X3<double,  float*>   v5;
    X3<int,     double*>  v6;
//    X3<int*,    int>      v7;
    X3<double*, double>   v8;
    
    DoWork<int> i0;
    DoWork<float*> pf;
    
    
    vector<int> intArray;
    vector<float> floatArray;
    
    intArray.push_back(5);
    floatArray.push_back(3.0f);
    
    int a = 5;
    int b = 3;
    
    int result = add<int>(a, b);
    
    int v = 0;
    float i = c_style_cast<int, float>(v);
    
    A<5> a2;
    B<7, A<5>, nullptr> b2;
    C<false, &foo> c2;           // function pointer
    D<&A<3>::foo> d;             // pointer to member function
    
    int x = add_i<3>(5);
    return 0;
}
