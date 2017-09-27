#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

int minTimeToDry(std::vector<int> &v, int k)
{
    std::priority_queue<int> pq;

    for (const auto ele: v) {
        pq.push(ele);
    }

    int total_minutes = 0;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        x -= total_minutes;
        if (x <= 0) {
            break;
        }
        if ( x <= k ) {
            total_minutes += 1;
        } else {
            int q = x/k, r = x%k;
            total_minutes += q;
            if (r != 0) {
                pq.push(r + total_minutes);
            }
        }
    }
    return total_minutes;
}

int main() {

    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    ifs >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        ifs >> v[i];
    }
    int k;
    ifs >> k;
    ofs << minTimeToDry(v, k) << std::endl;
    return 0;
}


