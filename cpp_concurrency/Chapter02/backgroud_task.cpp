#include <thread>

class background_task {
public:
    void operator()() const {
        // do _something()
        // do_something_else()
    }
};

background_task f;
std::thread my_thread(f);

std::thread my_thread2([] {
    // do_something
    // do_something_else
});

