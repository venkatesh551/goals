#include <iostream>

int getTimeToPrint(int *v, int n, int m) {

    int cnt = 0;
    for (int i = m - 1; i >= 0; --i) {
        if (v[i] > v[m]) {
            ++cnt;
        }
    }

    for (int i = m + 1; i < n; ++i) {
        if (v[i] > v[m]) {
            pos = i;
            break;
        }
    }

    return 0;
}

int main() {

    int tc;
    std::cin >> tc;
    int v[101];
    while (tc-- > 0) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
        }
        std::cout << getTimeToPrint(v, n, m);

    }
    return 0;
}

