#include <iostream>
#include <sstream>
#include <map>

int main() {

    int m, n;

    std::cin >> m >> n;
    std::map<std::string, int> mp;
    std::string keyword;
    int pay;
    while(m-- > 0) {
        std::cin >> keyword >> pay;
        mp[keyword] = pay;
    }
    std::string line, word;
    while(n > 0) {
        long long sum  = 0;
        while (true) {
            std::getline(std::cin, line);
            if (line == ".") {
                n--;
                break;
            }
            std::istringstream ss(line);
            while (ss >> word) {
                sum += mp[word];
            }
        }
        std::cout << sum << std::endl;
    }

    return 0;
}
