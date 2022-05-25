//
//  Component.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/25.
//

#ifndef Component_hpp
#define Component_hpp

#include <vector>

class Component {
public:
    Component(int val): val{val} {}
    virtual void add(Component* e) { c.push_back(e); }
    virtual ~Component() {}
private:
    int val;
    std::vector<Component *> c;
};

#endif /* Component_hpp */
