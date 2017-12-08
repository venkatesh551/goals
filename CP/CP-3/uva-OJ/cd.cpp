#include <iostream>
#include <set>

int main() {

    int n, m;
    while (true) {
        std::cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        std::set<int> s;
        int x;
        while(n-- > 0) {
            std::cin >> x;
            s.insert(x);
        }
        int count = 0;
        while (m-- > 0) {
            std::cin >> x;
            if (s.find(x) != s.end()){
                ++count;
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
