#include <cstdio>
#include <vector>
#include <queue>

int getMidElement(std::vector<int> &v, std::queue<int> &q) {

    while (v.size() < q.size()) {
        v.emplace_back(q.front());
        q.pop();
    }

    int median = v.back();
    v.pop_back();
    return median;
}


int main()
{
    int x;
    std::vector<int> v;
    std::queue<int> q;

    while (scanf("%d", &x) != EOF) {
        if (x == 0) {
            v.clear();
            std::queue<int> other;
            q.swap(other);
            putchar('\n');
        } else if (x == -1) {
            printf("%d\n", getMidElement(v, q));
        } else {
            q.push(x);
        }
    }
    return 0;
}

