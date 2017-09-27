#include <iostream>
#include <stack>
#include <queue>

int countTrues (bool p, bool q, bool r) {
    int cnt = 0;
    cnt += p;
    cnt += q;
    cnt += r;
    return cnt;
}

int main() {

    while (true) {
        int n;
        std::cin >> n;
        if(std::cin.eof()) {
            break;
        }

        std::stack<int> st;
        std::queue<int> q;
        std::priority_queue<int> pq;
        bool is_stack = true, is_queue = true, is_pq = true;

        for (int i = 0; i < n; ++i) {
            int x, y;
            std::cin >> x >> y;
            if (x == 1) {
                if (is_stack) {
                    st.push(y);
                }
                if (is_queue) {
                    q.push(y);
                }
                if (is_pq) {
                    pq.push(y);
                }

            } else {
                if (is_stack && (!st.empty()) && y == st.top()) {
                    st.pop();
                } else {
                    is_stack = false;
                }
                if (is_queue && (!q.empty()) && y == q.front()) {
                    q.pop();
                } else {
                    is_queue = false;
                }
                if (is_pq && (!pq.empty()) && y == pq.top()) {
                    pq.pop();
                } else{
                    is_pq = false;
                }
            }
        }
        int cnt = countTrues(is_stack, is_queue, is_pq);
        if (cnt > 1) {
            std::cout << "not sure" << std::endl;
        } else if (cnt == 0) {
            std::cout << "impossible" << std::endl;
        } else {
            if (is_stack)
                std::cout << "stack" << std::endl;
            else if (is_queue) {
                std::cout << "queue" << std::endl;
            } else { 
                std::cout << "priority queue" << std::endl;
            }
        }
    }

    return 0;
}
