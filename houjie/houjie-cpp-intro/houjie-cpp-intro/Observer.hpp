//
//  Observer.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/25.
//

#ifndef Observer_hpp
#define Observer_hpp

class Subject;

class Observer {
public:
    virtual void update(Subject* sub, int value) = 0;
};

#endif /* Observer_hpp */
