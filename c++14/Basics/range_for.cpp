#include <iterator>
#include <iostream>

int main()
{

    int a[10]{1, 2, 3, 4};

    for (int x : a) {
        std::cout << x << std::endl;
    }

    return 0;
}
