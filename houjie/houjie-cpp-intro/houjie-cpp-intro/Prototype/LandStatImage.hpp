//
//  LandStatImage.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/26.
//

#ifndef LandStatImage_hpp
#define LandStatImage_hpp
#include "Image.hpp"

#include <iostream>

class LandSatImage: public Image {
public:
    imageType returnType() override {
        return LSAT;
    }
    
    void draw() override {
        std::cout << "LandSatImage::draw" << std::endl;
    }
    
    Image * clone() override {
        return new LandSatImage(1);
    }
    
protected:
    // This is only called from clone()
    LandSatImage(int dummy) {
        _id = _count++;
    }
    
private:
    // Mechanism for initializing an Image subclass - this causes the
    // default ctor to be called, which registers the subclass's prototype
    static LandSatImage _landSatImage;
    
    // This is only called when the private static data member is initialized
    LandSatImage() {
        addPrototype(this);             // Registered into Image class!
    }
    
    // Normal "state" per instance mechanism
    int _id;
    static int _count;
};


#endif /* LandStatImage_hpp */
