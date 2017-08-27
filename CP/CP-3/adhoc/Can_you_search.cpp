#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
    int tc;
    
    std::cin >> tc;
    
    while (tc--) {
        int n, q;
        
        std::cin >> n >> q;
        std::vector<int> v(n);
        std::cin >> v[0];
        for (int i = 1; i < n; ++i) {
            std::cin >> v[i];
            v[i] = std::min(v[i], v[i-1]);
        }
        for (int i = 0; i < q; ++i) {
            int x;
            std::cin >> x;
            std::cout << v[x-1] << std::endl;
        }
    }    
        
    return 0;
}


