#include <iostream>


int medianOf3(int a, int b, int c)
{
    if (a < b) {
        if (b < c)
            return b;
        else
            return std::max(a, c);
    } else {
        if (b < c)
            return std::min(a, c);
        else
            return b;
    }

}


int main()
{

    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << medianOf3(a, b, c) << std::endl;

    return 0;
}
