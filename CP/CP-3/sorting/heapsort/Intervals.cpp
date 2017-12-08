#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

struct Interval {
    int start;
    int end;
    int cnt;

    Interval() {}

    Interval(int s, int e, int c) : start(s), end(e), cnt(c) {
    }

    bool operator() (const Interval &p, const Interval &q) {
        return p.start < q.start;
    }

};

int main() 
{
    int tc;
    std::cin >> tc;

    while (tc--) {
        int n, a, b, c;

        std::cin >> n;
        std::vector<Interval> v(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a >> b >> c;
            v[i] = Interval(a, b, c);
        }
        std::sort(v.begin(), v.end(), Interval());

    }

    return 0;
}



