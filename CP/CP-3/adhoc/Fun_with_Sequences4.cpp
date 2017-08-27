#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> s(n), q(n);
    for (int i = 0; i < n; ++i){
        std::cin >> s[i];
    }
    for (int i = 0; i < n; ++i){
        std::cin >> q[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = std::max((i - x), 0); 
                 j <= std::min((i + x), n-1); ++j) {
            if (s[i] == q[j]) {
                std::cout << (i + 1) << " ";
            }
        }
    }
    std::cout << "\n";

    return 0;
}

