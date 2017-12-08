#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

void readElements(std::set<int> &s, int n)
{
        int x;
        while(n-- > 0) {
            std::cin >> x;
            s.insert(x);
        }
}

int main()
{
    int n, m;

    while (true) {
        std::cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        std::set<int> v1;
        std::set<int> v2;
        readElements(v1, n);
        readElements(v2, m);
        std::vector<int> v_intersection;
        std::set_intersection(v1.begin(), v1.end(),
                          v2.begin(), v2.end(),
                          std::back_inserter(v_intersection));
        std::cout << v_intersection.size() << std::endl;
    }
    return 0;
}
