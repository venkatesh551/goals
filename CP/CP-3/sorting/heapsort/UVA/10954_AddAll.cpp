#include <iostream>
#include <algorithm>
#include <queue>

using LL = long long;

int main() {

    while (true) {
        int n;

        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            pq.push(x);
        }
        int result = 0;
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int sum = x + y;
            pq.push(sum);
            result += sum;
        }
        std::cout << result << std::endl;
    }
    return 0;
}
