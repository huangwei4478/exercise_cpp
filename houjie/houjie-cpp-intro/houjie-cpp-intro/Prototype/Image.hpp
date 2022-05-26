//
//  Image.hpp
//  houjie-cpp-intro
//
//  Created by 黄炜 on 2022/5/26.
//

#ifndef Image_hpp
#define Image_hpp

enum imageType {
    LSAT,
    SPOT
};

class Image {
public:
    virtual void draw() = 0;
    static Image* findAndClone(imageType);
    virtual ~Image() {}
protected:
    virtual imageType returnType() = 0;
    virtual Image* clone() = 0;
    // As each subclass of Image is declared, it registers its prototype
    static void addPrototype(Image *image) {
        _prototypes[_nextSlot++] = image;
    }
    
private:
    // addPrototype() saves each registered prototype here
    static Image* _prototypes[10];
    static int _nextSlot;
};


#endif /* Image_hpp */
