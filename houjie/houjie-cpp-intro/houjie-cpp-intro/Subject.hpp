//
//  Subject.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/25.
//

#ifndef Subject_hpp
#define Subject_hpp
#include <vector>
#include "Observer.hpp"

class Subject {
public:
    void attach(Observer* obs) {
        m_views.push_back(obs);
    }
    
    void set_val(int value) {
        m_value = value;
        notify();
    }
    
    void notify() {
        for (const auto& myView: m_views) {
            myView -> update(this, m_value);
        }
    }
private:
    int m_value;
    std::vector<Observer *>m_views;
};

#endif /* Subject_hpp */
