#include <iostream>
#include <algorithm>

int main()
{
    int n;
    
    std::cin >> n;
    std::string s;
    std::cin >> s;
    
    char mapping[128] = {0};
    
    for (int i = 0; i < n-1; ++i) {
        mapping[s[i]] = s[i+1];
    }
    mapping[s[n-1]] = s[0];
    
    int m;
    std::cin >> m;
    std::string line;
    /* discard new line */
    std::getline(std::cin, line);
    while (m--) {
        std::getline(std::cin, line);
        for (auto ch : line) {
            char c = mapping[ch];
            if ( c != 0){
                std::putchar(c);
            } else {
                std::putchar(ch);
            }
        }
        std::putchar('\n');
    }

    return 0;
}

