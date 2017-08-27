#include <iostream>
#include <vector>
#include <algorithm>

void printEqualElementsWithEqualIndices(std::vector<int> &s, std::vector<int> &q)
{
    int n = std::min(s.size(), q.size());
    
    for (int i = 0 ; i < n ; ++i) {
    
        if (s[i] == q[i]) {
            std::cout << (i + 1) << " ";
        }
    }
    std::cout << "\n";

}

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
    printEqualElementsWithEqualIndices(s, q);
    return 0;
}

