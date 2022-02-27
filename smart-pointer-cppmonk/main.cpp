#include <iostream>
#include <string>
#include <thread>
#include <vector>

// https://www.youtube.com/watch?v=Zt0zUcDHi7I

template<typename T>
using uptr = std::unique_ptr<T>;

struct Message {
    std::string content;

    Message(const std::string& str): content{str} {}
};

std::vector<std::thread> allThreads;

void sendEmailFn(uptr<Message> msg, uptr<std::string> email) {
    std::cout << "sending email to " << *email << "..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Done!" << std::endl;
}

void sendEmail(uptr<Message> msg, uptr<Message> email) {
    allThreads.emplace_back(sendEmailFn, std::move(msg), std::move(email));
}

template<typename T>
class UPtr {
public:
   UPtr(T *p) {
       internal_ptr = p;
   }

   ~UPtr() {
       delete internal_ptr;
   }

private:
    T *internal_ptr;
};


int main() {
    {
        auto msg = uptr<Message>(new Message{"hello john, how's it going?"});
        auto to  = uptr<Message>(new Message{"jane@server.com"});
        sendEmail(std::move(msg), std::move(to));
    }
    // make_unique, make_shared, just to make sure no memory leak if evaluated error
    {
        auto msg = std::make_unique<Message>("Hey jane, are you up for lunch tomorrow?");
        auto to  = std::make_unique<Message>("john@server.com");
        sendEmail(std::move(msg), std::move(to));
    }

    // when you want a heap object
    // and want it to automatically deallocated
    // when nobody uses it

    for (auto& thread: allThreads) { thread.join(); }
    return 0;
}


