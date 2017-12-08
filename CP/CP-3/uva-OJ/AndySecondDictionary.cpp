#include <iostream>
#include <set>

int main() {

    std::string word;
    std::set<std::string> dict;
    std::string current{};
    while (std::cin >> word) {
        for (char c: word) {
            if (std::islower(c) || std::isupper(c) || c == '-') {
                current += std::tolower(c);
            } else if (current.length() > 0) {
                dict.insert(current);
                current = "";
            }
        }
        int n = current.length();
        if (n > 1 && current[n-1] == '-') {
            current.pop_back();
        } else if (n > 0) {
            dict.insert(current);
            current = "";
        }
    }

    for (const auto &ele : dict) {
        std::cout << ele << std::endl;
    }
    return 0;
}

