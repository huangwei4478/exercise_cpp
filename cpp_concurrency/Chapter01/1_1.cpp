#include <iostream>
#include <thread>
/* g++ 1_1.cpp -o 1_1.out -lpthread */
void hello() {
    std::cout << "Hello Concurrency World\n";
}

int main() {
    std::thread t(hello);
    t.join();
}