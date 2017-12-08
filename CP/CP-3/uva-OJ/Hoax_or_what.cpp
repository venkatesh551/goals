#include <iostream>
#include <set>

using LL = long long;

int main()
{
    int n;

    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::multiset<int> s{};
        LL sum = 0;
        for (int i = 0; i < n; ++i) {
            int m, val;
            std::cin >> m;
            for (int i = 0; i < m; ++i) {
                std::cin >> val;
                s.insert(val);
            }
            auto first = s.begin();
            auto last = std::prev(s.end());
            sum += *last - *first;
            s.erase(first);
            s.erase(last);
        }
        std::cout << sum << std::endl;
    }

    return 0;
}

