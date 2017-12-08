#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void readElements(std::vector<int> &v, int n) 
{
    int x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        v[i] = x;
    }
}

int main()
{
    int tc;
    std::cin >> tc;
    while (tc--) {
        int m, n;
        std::cin >> m >> n;
        std::vector<int> A(m), u(n);
        std::multiset<int> s{};
        readElements(A, m);
        readElements(u, n);
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = u[i];
            while ((int)s.size() < cnt) {
                s.insert(A[idx++]);
            }
            std::cout << *std::prev(s.cend()) << std::endl;
        }
    }

    return 0;
}


