#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using pii = std::pair<int, int>;

int main() 
{
    int tc;
    std::cin >> tc;

    while (tc--) {
        int n, x, y;

        std::cin >> n;
        std::vector<pii> v(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> x >> y;
            v[i] = std::make_pair(x, y);
        }
        std::sort(v.begin(), v.end());
        int end = v[0].second, cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (v[i].first < end) {
                ++cnt;
                end = std::min(end, v[i].second);
            } else {
                end = v[i].second;
            }
        }
        std::cout << (n - cnt) << std::endl;
    }

    return 0;
}



