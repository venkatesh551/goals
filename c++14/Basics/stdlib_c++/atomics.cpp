#include <iostream>
#include <atomic>

int main() {

    std::atomic<int> x{};

    std::cout << x << std::endl;
    if (x.is_lock_free()) {
        std::cout << "true" << std::endl;
    }
    /* x = 12;
    std::cout << x << std::endl;
    x.store(10);
    int t = 13;
    int t2 = x.exchange(t);
    */
    x = 13;
    int rt = 13;
    std::cout << "before  x = " << x  << "rt = " << rt << std::endl;
    bool b = x.compare_exchange_strong(rt, 0);
    std::cout << "b = " << b << " rt = " << rt << " x = "  << x << std::endl;
    b = x.compare_exchange_strong(rt, 0);
    std::cout << "b = " << b << " rt = " << rt << " x = "  << x << std::endl;

    return 0;
}
