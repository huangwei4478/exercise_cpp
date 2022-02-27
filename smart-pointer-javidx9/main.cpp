#include <iostream>
#include <memory>

struct sSomeObject {
    int x = 0x9343434;
    int y = 0x9384349;

    sSomeObject() {
        x = 0x3434343;
        y = 0x3434322;
    }
};

int main() {

    std::shared_ptr<sSomeObject> sharedPtr = std::make_shared<sSomeObject>();

    auto sharedPtr2 = sharedPtr;

    std::unique_ptr<sSomeObject> uniquePtr = std::make_unique<sSomeObject>();



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
