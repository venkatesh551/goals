#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// output v[i] to os if v[i]%m==0
void print_modulo(std::vector<int>& v, std::ostream& os, int m) {
    std::for_each(std::begin(v), std::end(v),
                  [&os, m](int x)  { if (x % m == 0) os << x << '\n'; }
                 );
}


// alternative Way of doing the above code

// output v[i] to os if v[i]%m==0
void print_modulo1(const std::vector<int>& v, std::ostream& os, int m)
{

    class Modulo_print {
    private:
        std::ostream& os; // members to hold the capture list
        int m;
    public:
        Modulo_print(std::ostream& s, int mm) :os(s), m(mm) {}
        void operator()(int x) const
        { if (x%m==0) os << x << '\n'; }
    };

    std::for_each(begin(v),end(v),Modulo_print{os,m});
}

