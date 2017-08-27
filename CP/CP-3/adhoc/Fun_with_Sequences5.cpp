#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int i;
    for (i = 1; i < n && (a[i] < a[i-1]); ++i)
        ;
    for (i = i + 1 ; i < n && (a[i] > a[i-1]); ++i)
        ;
    if (i >= n) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

