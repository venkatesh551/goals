#include <iostream>
#include <vector>
#include <algorithm>

void readElements(std::vector<int> &v, int n) 
{
    int x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        v[i] = x;
    }
    std::sort(v.begin(), v.end());
}

int findNoOfElementsToRemove(std::vector<int> &p,
                             std::vector<int> &q) {

    auto first1 = p.cbegin();
    auto first2 = q.cbegin();
    int count = 0;

    while (first1 != p.cend() && first2 != q.cend()) {
//        std::cout << *first1 << " " << *first2 ;
        if (*first1 < *first2) {
            ++first1;
            ++count;
        } else {
            if (*first1 == *first2) {
                first1++;
            } else {
                ++count;
            }
            ++first2;
        }
//        std::cout << " count =" << count << std::endl;
    }
    count += (p.cend() - first1) + (q.cend() - first2);
    return count;
}

int main()
{

    int tc;

    std::cin >> tc;
    while (tc--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> p(n), q(m);
        readElements(p, n);
        readElements(q, m);
        std::cout << findNoOfElementsToRemove(p, q) << std::endl;
    }

    return 0;
}

