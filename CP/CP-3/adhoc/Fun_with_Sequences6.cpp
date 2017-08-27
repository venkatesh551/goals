#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int> &v)
{
    for (const auto ele: v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}

int main()
{
    int n;
    std::cin >> n;
    
    int sum1 = 0, sum2 = 0;
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i){
        std::cin >> s[i];
        sum1 += s[i];
    }
    
    int m;
    std::cin >> m;
    std::vector<int> q(m);
    for (int i = 0; i < m; ++i){
        std::cin >> q[i];
        sum2 += q[i];
    }
    if (sum2 < sum1) {
        printVector(s);
    } else {
        printVector(q);
    }

    return 0;
}

