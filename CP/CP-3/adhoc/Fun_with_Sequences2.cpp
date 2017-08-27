#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i){
        std::cin >> s[i];
    }
    
    int m;
    std::cin >> m;
    std::vector<int> q(m);
    for (int i = 0; i < m; ++i){
        std::cin >> q[i];
    }
    
    for (auto ele: s) {
        if (std::binary_search(q.begin(), q.end(), ele)){
            std::cout << ele << " ";
        }       
    }
    std::cout << "\n";
    
    return 0;
}

