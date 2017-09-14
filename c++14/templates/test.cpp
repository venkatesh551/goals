#include <iostream>


int main()
{
    std::string str;
    std::cin >> str;
    std::cout << std::hex << std::stoul(str, nullptr, 16) << std::endl;

    return 0;
}
