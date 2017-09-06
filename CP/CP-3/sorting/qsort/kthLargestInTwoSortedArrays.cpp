#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>



int kthLargest(std::vector<int> &a, std::vector<int> &b, int k) {



}

int main() {

    int n1, n2, n;

    std::cin >> n1 >> n2;
    n = n1 + n2;
    std::vector<int> a(n1), b(n2), c(n);
    for (int i = 0; i < n1; ++i) {
        a[i] = (10 * i + n1) % 101;
    }
    for (int i = 0; i < n2; ++i) {
        b[i] = (11 * i + n2) % 107;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    for (int k = 0; k < n; ++k) {
        int ele = kthLargest(a, b, k);
        std::cout << ele << std::endl;
        if (ele != c[n-k]) {
            std::cerr << "Wrong answer" << std::endl;
            assert(false);
        }
    }
    return 0;
}
