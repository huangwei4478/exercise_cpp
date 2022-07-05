//
//  vector.h
//  Cpp_template
//
//  Created by wei on 2022/7/5.
//

#ifndef vector_h
#define vector_h

template <typename T>
class vector {
public:
    void clear();
private:
    T* elements;
};

template <typename T>
void vector<T>::clear() {
    // do nothing yet
}


#endif /* vector_h */
