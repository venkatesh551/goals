#include <vector>
#include <iostream>

void print(std::vector<int> && v)
{
    std::cout << " in print =   " << v.size() << std::endl;
}

int main() {
    std::vector<int> v(10000, 23);
    print(std::move(v));
    std::cout << "v.size() =  " << v.size() << std::endl;

    return 0;
}
