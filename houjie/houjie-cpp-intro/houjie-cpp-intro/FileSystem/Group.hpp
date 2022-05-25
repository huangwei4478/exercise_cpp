//
//  Group.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/25.
//

#ifndef Group_hpp
#define Group_hpp

#include "Component.hpp"

class Group: public Component {
public:
    Group(int val): Component(val) {}
    void add(Component *e) override {
        // ...
    }
    
    virtual ~Group() {}
};

#endif /* Group_hpp */
