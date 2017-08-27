#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int tc;
    std::cin >> tc;
    
    while (tc--){
     
        int n, x, y;
        
        std::cin >> n >> x >> y;
        for (int a = x; a < n; a += x) {
            if (a % y != 0) {
                std::cout << a << " ";
            }            
        }
        std::cout << "\n";
    }
    return 0;
}

