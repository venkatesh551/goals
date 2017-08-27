#include <iostream>
#include <algorithm>
#include <cstdio>

int main() 
{

    int tc;
    
    std::cin >> tc;
    
    while (tc--) {
        int r, c;
        
        std::cin >> r >> c;
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int c = (i + j) % 2;
                if (c == 0) {
                    std::putchar('*');
                } else {
                    std::putchar('.');
                }
            }
            std::putchar('\n');
        }
        if (tc )
            std::putchar('\n');
    }    
        
    return 0;
}

