#include <iostream>
#include <map>

template<class C>
void print_modulo(const C& v, std::ostream& os, int m)
// output v[i] to os if v[i]%m==0
{
    for (auto x : v)
        if (x.first % m ==0) os << x.first << '\n';
}


int main() {

    std::map<int, int> mp = { {1, 2}, {2, 3}, {3, 4}};
    print_modulo(mp, std::cout, 2);

    return 0;
}
