#include <iostream>
#include <map>
#include <cstring>


int main() {

    int tc;
    std::string treeName, num;
    std::getline(std::cin, num);
    std::getline(std::cin, treeName); // read blank line
    tc = atoi(num.data());
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    // std::cout.setf(std::ios::showpoint);
    std::cout.precision(4);
    while (tc--) {
        std::map<std::string, int> freq;
        int count = 0;
        while (true) {
            std::getline(std::cin, treeName);
            if (std::cin.eof() || treeName.empty()) {
                break;
            }
            freq[treeName]++;
            count++;
        }
        for (auto const &ele : freq) {
            std::cout << ele.first << " " << (100.0 * ele.second)/count << std::endl;
        }
        if (tc > 0)
            std::cout << std::endl;
    }
    return 0;
}
