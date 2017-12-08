#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using pii = std::pair<int, int>;

struct Compare {

    bool operator() (const pii &a, const pii &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

int main() {

    std::string s;
    std::priority_queue<pii, std::vector<pii>, Compare> pq;
    std::map<int, int> id_map;
    int k, id, period;

    while (true) {

        std::cin >> s;
        if (s == "#") {
            break;
        }
        std::cin >> id >> period;
        id_map[id] = period;
        pq.push(std::make_pair(period, id));
    }
    std::cin >> k;
    while (k--) {
        pii ele = pq.top();
        pq.pop();
        printf("%d\n", ele.second);
        pq.push({id_map[ele.second] + ele.first, ele.second});
    }
    return 0;
}



