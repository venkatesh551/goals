#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using LL = long long;
using pii = std::pair<LL, LL>;

struct Compare {

    bool operator() (const pii &p, const pii &q) {
        return p.second > q.second;
    }

};

int main() {

    int n;
    std::cin >> n;
    std::priority_queue<pii, std::vector<pii>, Compare> minPQ;
    std::vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        v[i] = std::make_pair(x, y);
    }
    std::sort(v.begin(), v.end());
    LL current_time = v[0].first, total_waiting_time = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].first <= current_time) {
            minPQ.push(v[i]);
        } else {
            while (!minPQ.empty() && v[i].first > current_time) {
                pii ele = minPQ.top();
                minPQ.pop();
                current_time += ele.second;
                total_waiting_time += current_time - ele.first;
            }
            if (minPQ.empty()) {
                current_time = std::max(current_time, v[i].first);
            }
            minPQ.push(v[i]);
        }
    }
    while (!minPQ.empty()) {
        pii ele = minPQ.top();
 //       std::cout << ele.first << " " << ele.second << "\n";
        minPQ.pop();
        current_time += ele.second;
        total_waiting_time += current_time - ele.first;
    }
    std::cout << total_waiting_time/n << std::endl;

    return 0;
}


