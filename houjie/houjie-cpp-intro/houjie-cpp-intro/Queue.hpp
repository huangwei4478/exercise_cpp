//
//  Queue.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/25.
//

#ifndef Queue_hpp
#define Queue_hpp
#include <deque>

/// Composition Example
template <typename T>
class Queue {
public:
    bool empty() const { return c.empty(); }
    size_t size() const { return c.size(); }
    T& front() { return c.front(); }
    T& back() { return c.back(); }
    
    void push(const T& x) { c.push_back(x); }
    void pop() { c.pop_front(); }
protected:
    std::deque<T> c;
};

#endif /* Queue_hpp */
