//
//  SpotImage.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/26.
//

#ifndef SpotImage_hpp
#define SpotImage_hpp

#include "Image.hpp"
#include <iostream>

class SpotImage: public Image {
public:
    imageType returnType() override {
        return SPOT;
    }
    
    void draw() override {
        std::cout << "SpotImage::draw" << std::endl;
    }
    
    Image * clone() override {
        return new SpotImage(1);
    }
    
protected:
    // This is only called from clone()
    SpotImage(int dummy) {
        _id = _count++;
    }
    
private:
    static SpotImage _spotImage;
    SpotImage() {
        addPrototype(this);
    }
    
    int _id;
    static int _count;
};

#endif /* SpotImage_hpp */
