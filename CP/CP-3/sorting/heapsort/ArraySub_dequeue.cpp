#include <iostream>
#include <queue>
#include <vector>


std::vector<int> slidingWindow(std::vector<int> &v, int k) {

    int n = v.size();
    std::vector<int> result;
    std::deque<int> q;

    for (int i = 0; i < k; ++i) {
        while ((!q.empty()) && v[i] >= v[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    for (int i = k; i < n; ++i) {
        result.push_back(v[q.front()]);
        while (!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        while (!q.empty() && v[i] >= v[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    result.push_back(v[q.front()]);
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

