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
            
            if (i == 0 || i == (r - 1)){
                for (int j = 0; j < c; ++j) {
                    std::putchar('*');
                }
            } else {
                for (int j = 0; j < c; ++j) {
                    if (j == 0 || j == (c - 1)) {
                        std::putchar('*');
                    } else {
                        std::putchar('.');
                    } 
                          
                }
            }
            std::putchar('\n');   
        }
        if (tc )
            std::putchar('\n');
    }    
        
    return 0;
}


