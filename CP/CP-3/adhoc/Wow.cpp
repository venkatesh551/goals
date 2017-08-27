#include <iostream>

int main() 
{
    int n;
    std::cin >> n;
    
    std::putchar('W');
    for (int i = 0; i < n; ++i) {
        std::putchar('o');
    }
    std::putchar('w');
    std::putchar('\n');
    return 0;
}
