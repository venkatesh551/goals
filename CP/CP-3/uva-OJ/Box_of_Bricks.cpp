#include <iostream>
#include <vector>


int main() {

    int n, cnt = 0;
    while (std::cin >> n && n > 0) {

        std::vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
            sum += v[i];
        }
        int k = 0, q = sum/n;
        for (auto const ele : v) {
            if (ele > q) {
                k += ele - q;
            }
        }
        std::cout << "Set #" << ++cnt << std::endl;
        std::cout << "The minimum number of moves is " << k << "." ;
        std::cout << std::endl << std::endl;
    }
    return 0;
}
