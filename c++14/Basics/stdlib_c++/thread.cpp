#include <iostream>
#include <thread>

int main() {


    std::cout << " cores = " << std::thread::hardware_concurrency() << std::endl;

    return 0;
}
