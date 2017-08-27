#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
    int tc;
    
    std::cin >> tc;
    
    while (tc--) {
        int m, n, ci, cj;
        
        std::cin >> m >> n >> ci >> cj;
        --ci, --cj;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = abs (ci - i);
                int y = abs (cj - j);
                if (x == y) {
                    std::putchar('*');
                } else {
                    std::putchar('.');
                }
            }
            std::putchar('\n');
        }
        if (tc)
            std::putchar('\n');
    }    
        
    return 0;
}


