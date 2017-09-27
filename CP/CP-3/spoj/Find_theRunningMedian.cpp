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

double getMidElement(MinPQ &upper, std::priority_queue<int> &lower) {

    if (upper.size() == lower.size()) {
        return (upper.top() + lower.top())/2.0;
    } else if (lower.size() > upper.size()) {
        return lower.top();
    } else {
        return upper.top();
    }

}

int main()
{
    int n;
    scanf("%d", &n);

    std::priority_queue<int> lower; //max-heap
    MinPQ larger; // min-heap

    while (n-- > 0) {
        int x;
        scanf("%d", &x);
        addElement(x, lower, larger);
        balanceHeaps(lower, larger);
        printf("%0.1f\n", getMidElement(larger, lower));
    }

    return 0;
}


