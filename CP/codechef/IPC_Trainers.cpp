#include <iostream>
#include <queue>          // std::priority_queue
#include <vector>
#include <utility>

using namespace std;

using pii = pair<int, int>;
using LL = long long;

int main() {
    int T;
    cin >> T;
    
    while (T--){
        int N, D;
        cin >> N >> D;
       
        vector<vector<pii>> v (D + 1);
        for (int i = 0; i < N; ++i) {
            int d, t, s;
            cin >> d >> t >> s;
            v[d].push_back(make_pair(s, t));
        }

        priority_queue<pii> queue;
        for(int cur_day = 1; cur_day <= D; cur_day++) {
            for (auto ele : v[cur_day]) {
                queue.emplace(ele);
            }

            if (!queue.empty()) {
                const pii ele = queue.top();
                queue.pop();
                if (ele.second > 1) {
                    queue.emplace(make_pair(ele.first, ele.second - 1));
                }
            }
        }

        LL ans = 0;
        while (!queue.empty()) {
            const pii & top_ele = queue.top();
            ans += top_ele.first * static_cast<LL>(top_ele.second);
            queue.pop();
        }
        cout << ans << endl;
    }
    
    return 0;
}


