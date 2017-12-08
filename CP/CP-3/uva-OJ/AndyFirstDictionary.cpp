#include <iostream>
#include <set>

int main() {

    std::string word;
    std::set<std::string> dict;
    while (std::cin >> word) {
        std::string current;
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            char c = word[i];
            if (std::islower(c) || std::isupper(c)) {
                current += std::tolower(c);
            } else if (current.length() > 0) {
                dict.insert(current);
                current = "";
            }
        }
        if (current.length() > 0) {
            dict.insert(current);
        }
    }
    for (const auto &ele : dict) {
        std::cout << ele << std::endl;
    }
    return 0;
}
