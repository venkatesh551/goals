#include <iostream>
#include <sstream>


int main() {

    std::stringstream ss;

    ss << "hello";
    ss << " world";

    std::cout << " seek :" << ss.tellp() << "\n";
    std::string test;
    ss >> test;
    std::cout << test << " :" << ss.tellp() << "\n";
    ss.flush();
    std::cout << test << " :" << ss.tellp() << "\n";
    ss.seekg (0, ss.beg);
    ss >> test;
    std::cout << test << " $\n";

    return 0;
}
