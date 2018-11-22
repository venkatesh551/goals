#include <iostream>
#include <thread>
#include <mutex>

std::mutex m{};

void hello() {

    m.lock();
    std::cout << "hello-acquired lock" << std::endl;
    m.unlock();

}

void world() {

    m.lock();
    std::cout << "w : acquired lock" << std::endl;
    m.unlock();
}

int main() {

    std::thread t1{hello};
    std::thread t2{world};

    t1.join();
    t2.join();
    return 0;
}
