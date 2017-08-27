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
        int totalRows = 3 * r + 1;
        int totalColumns = 3 * c + 1;
        for (int i = 0; i < totalRows; ++i) {
            
            if (i % 3 == 0){
                for (int j = 0; j < totalColumns; ++j) {
                    std::putchar('*');
                }
            } else {
                for (int j = 0; j < totalColumns; ++j) {
                    if (j % 3  == 0) {
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


