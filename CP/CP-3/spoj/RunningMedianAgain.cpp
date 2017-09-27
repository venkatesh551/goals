#include <cstdio>
#include <vector>
#include <queue>

using MinPQ = std::priority_queue<int, std::vector<int>, std::greater<int>>;

void addElement(int x, std::priority_queue<int> &smaller, MinPQ &larger) {

    if (smaller.size() == 0 || x < smaller.top()) {
        smaller.push(x);
    } else {
        larger.push(x);
    }
}

void balanceHeaps(std::priority_queue<int> &lower, MinPQ &upper) {

    int diff = lower.size() - upper.size();

    if (diff == 2){
        upper.push(lower.top());
        lower.pop();
    } else if (diff == -2) {
        lower.push(upper.top());
        upper.pop();
    }
}

int getMidElement(MinPQ &upper, std::priority_queue<int> &lower) {

    int x = 0;

    if (lower.size() >= upper.size()) {
        x = lower.top();
        lower.pop();
    } else {
        x = upper.top();
        upper.pop();
    }
    balanceHeaps(lower, upper);
    return x;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    std::priority_queue<int> lower;
    MinPQ upper;

    while (tc-- > 0) {
        int x;
        while(scanf("%d", &x)) {
            if (x == 0) {
                std::priority_queue<int> emptyPQ;
                MinPQ emptyMinHeap;
                lower.swap(emptyPQ);
                upper.swap(emptyMinHeap);
                break;
            } else if (x == -1) {
                printf("%d\n", getMidElement(upper, lower));
            } else {
                addElement(x, lower, upper);
                balanceHeaps(lower, upper);
            }
        }
    }

    return 0;
}

