//
//  main.cpp
//  cppTemplateMetaProgramming
//
//  Created by wei on 2019/7/3.
//  Copyright © 2019 wei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <functional>

template <typename T>
bool equivalent(const T& a, const T& b) {
    return !(a < b) && !(b < a);
}

template <typename T = int>
class bignumber {
    T _v;
public:
    bignumber(T a) : _v(a) {}
    inline bool operator<(const bignumber& b) const;
};

template <typename T>
bool bignumber<T>::operator<(const bignumber<T> &b) const {
    return _v < b._v;
}
    
template<typename T, int N>
class Vec {
    T _v[N];
    // -- primary template, default implementation
};

template<>
class Vec<float, 4> {
    float _v[4];
    // 对 Vec<float, 4> 进行专门实现，可能利用向量指令进行加速
};
    
template<int N>
class Vec<bool, N> {
    char _v[(N + sizeof(char) - 1)/sizeof(char)];
    // 对Vec<bool, N> 进行专门实现，用一个比特位代表 bool
};

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
}

template <typename T> int compare(const T &v1, const T &v2) {
    if (std::less<T>()(v1, v2)) return -1;
    if (std::less<T>()(v2, v1)) return 1;
    return 0;
}

template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // constructors
    Blob();
    Blob(std::initializer_list<T> il);
    // number of elements in the blob
    size_type size() const { return data -> size(); };
    bool empty() const { return data -> empty(); }
    // add and remove methods
    void push_back(const T &t) { data -> push_back(t); }
    void push_back(T &&t) { data -> push_back(std::move(t)); }
    T& back();
    T& operator[] (size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};
    
template <typename T> class BlobPtr {
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { }
private:
    // check returns  a shared_ptr to the vector if the check succeeds
    std::shared_ptr(std::vector<T>>check(std::size_t, const std::string&)) const;
    
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++(*this);
    return ret;
}
    
template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data -> back();
}
    
template <typename T>
T& Blob<T>::operator[](std::size_type i) {
    // if i is too big, check will throw, preventing access to nonexistent element
    check(i, "subscript out of range");
    return (*data)[i];
}
    
template <typename T>
void Blob<T>::check(std::size_type i, const std::string &msg) const {
    if (i >= data -> size()) {
        throw std::out_of_range(msg);
    }
}
    
template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) {}

template <typename T> class BlobPtr2 {
public:
    BlobPtr2(): curr(0) {}
    BlobPtr2(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr2& operator++();
    BlobPtr2& operator--();
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
}
    
template <typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F()) {
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    bignumber<>a(1), b(1);
    std::cout << equivalent(a, b) << std::endl;
    std::cout << equivalent(1, 2) << std::endl;
    return 0;
}
