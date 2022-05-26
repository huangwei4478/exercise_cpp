//
//  Image.cpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/26.
//

#include "Image.hpp"

// static member
Image* Image::_prototypes[];
int Image::_nextSlot;

// static function
Image* Image::findAndClone(imageType type) {
    for (int i = 0; i < _nextSlot; ++i) {
        if (_prototypes[i] -> returnType() == type) {
            return _prototypes[i] -> clone();
        }
    }
    return nullptr;
}
