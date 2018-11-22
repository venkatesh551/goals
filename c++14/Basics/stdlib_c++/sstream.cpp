#include <iostream>
#include <sstream>
#include <cassert>


int main() {

    std::stringstream ss{"abcd"};

    char buf[10] = {0};
    ss.read(buf, 5);
    std::cout << "eof  == " << ss.eof() << std::endl;
    assert(ss.good());
    std::cout << buf << std::endl;

    return 0;
}
