#include <iostream>

using LL = unsigned long long;

int main() 
{
    int tc;
    std::string line;

    std::cin >> tc;
    while (tc--) {
        int k;
        int cents;
        char c;
        double asciiMap[256] = {0.0};
        std::cin >> k;
        while (k-- > 0) {
            std::cin >> c >> cents;
            asciiMap[c] = cents;
        }
        int m;
        std::cin >> m;
        // read "\n"
        std::cin.ignore();
        double sum = 0;
        while (m-- > 0) {
            std::getline(std::cin, line);
            for (char c: line) {
                sum += asciiMap[c];
            }
        }
        printf("%0.2lf$\n", sum/100.0);
    }
    return 0;
}

