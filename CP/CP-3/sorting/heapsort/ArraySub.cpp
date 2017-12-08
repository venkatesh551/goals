#include <iostream>
#include <queue>
#include <vector>

using pii = std::pair<int, int>;

std::vector<int> slidingWindow(std::vector<int> &v, int k) {

    int n = v.size();
    std::vector<int> result;
    std::priority_queue<pii> maxPQ;

    for (int i = 0; i < k; ++i) {
        maxPQ.push(std::make_pair(v[i], i));
    }

    for (int i = k; i < n; ++i) {
        pii ele = maxPQ.top();
        result.push_back(ele.first);
        while (!maxPQ.empty() && maxPQ.top().second <= i - k) {
            maxPQ.pop();
        }
        maxPQ.push(std::make_pair(v[i], i));
    }
    result.push_back(maxPQ.top().first);
    return result;
}

int main() {

    int n, k;

    std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::cin >> k;
    std::vector<int> result = slidingWindow(v, k);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

