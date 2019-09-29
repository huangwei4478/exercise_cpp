#include <thread>

/* A function that returns while a thread still has access to local variables */
struct func {
    int& i;
    func(int& i_): i(i_) {}
    void operator()() {
        for(unsigned j = 0; j < 1000000; ++j) {
            // do something                     
            // Potential access to dangling reference
        }
    }
};

void oops() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach();                                 // new thread might be running while the main function can be destroyed
}